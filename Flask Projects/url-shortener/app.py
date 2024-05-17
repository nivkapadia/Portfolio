from flask import Flask, render_template, request, redirect, url_for, flash, abort, session, jsonify
import json
import os.path
from werkzeug.utils import secure_filename


app = Flask(__name__)
#Secret_key is used for flashing a message to the user
app.secret_key = "ajkds3209dfkh032947"

#basic home page route
@app.route("/")
def home():
    return render_template("index.html", codes=session.keys()) 

@app.route("/your-url", methods=["GET", "POST"])
def your_url():
    if request.method == "POST":
        urls = {}


        #checks if urls.json already exists
        if os.path.exists("urls.json"):
            #if urls.json does exit, it will load all the data from urls.json to our dictionary which is empty now as changes to server will reset the dictionary
            #question to ask: Why can't we not simply append to dictionary instead?
            #answer: Every time the server restarts, the dictionary is empty, it is important to store the data in some file
            with open("urls.json", "r") as url_file:
                urls = json.load(url_file)


        if request.form.get("Short") in urls.keys():
                flash("The short name is already taken")
                return redirect(url_for("home"))
        

        # if "url" in request.form.keys():
        #     urls[request.form.get("Short")] = {"url": request.form.get("url")}
        # else:
        #     f = request.files["File"]
        #     full_name = request.form["Short"] + secure_filename(f.filename)
        #     f.save("/home/nivkapadia/Code/Flask/url-shortener/" + full_name)
        #     urls[request.form.get("Short")] = {"file": full_name}

        if "File" in request.files.keys():
             f = request.files["File"]
             full_name = request.form.get("Short") + secure_filename(f.filename)
             f.save("/home/nivkapadia/Code/Flask/url-shortener/static/user_files" + full_name)
             urls[request.form["Short"]] = {"file": full_name}
        else:
             urls[request.form["Short"]] = {"url": request.form["url"]}

            
        with open ("urls.json", "w") as url_file:
            json.dump(urls, url_file, indent = 4)
            session[request.form['Short']] = True

        return render_template("your-url.html", something=request.form.get("Short"))
    else:
        return redirect(url_for("home"))
    
@app.route("/<string:code>")
def redirectURL(code):
    if os.path.exists("urls.json"):
        with open("urls.json") as url_file:
            urls = json.load(url_file)
            if code in urls.keys():
                if "url" in urls[code].keys():
                    return redirect(urls[code]['url'])
                else:
                    return redirect(url_for("static", filename="user_files" + urls[code]["file"]))
    return abort(404)

@app.errorhandler(404)
def page_not_found(error):
    return render_template("error.html"), 404

@app.route("/api")
def sessionAPI():
    return jsonify(list(session.keys()))