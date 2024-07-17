import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    scripts = db.execute(
        "SELECT distinct(symbol), sum(quantity) as 'quantity', ROUND(avg(buy_price), 2) as 'avg_price', ROUND((sum(quantity) * avg(buy_price)), 2) as 'buy_value' from transactions where id = ? GROUP BY symbol;", session["user_id"])
    cash = db.execute("SELECT ROUND(cash, 2) as 'cash' FROM users WHERE id = ?", session["user_id"])
    cash = cash[0]['cash']
    total_value = sum(script['buy_value'] for script in scripts) + cash
    print(scripts)
    # for i in range(1, len(scripts)):
    #     try:
    #         scripts[i]['avg_price'] = float(scripts[i]['avg_price'])
    #     except ValueError:
    #         return apology("some error occured", 400)

    # for i, script in range(0, len(scripts)), scripts:
    #     scripts[i]['current_price'] = lookup(script['symbol'])

    return render_template("index.html", scripts=scripts, cash=cash, total_value=round(total_value, 2))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if not symbol or not lookup(symbol):
            return apology("Input not given/symbol does not exist", 400)
        if not shares:
            return apology("Please enter a proper quantity", 400)
        try:
            shares = int(shares)
        except ValueError:
            return apology("Please enter a valid quantity", 400)
        #  if not shares.is_integer():
        #     return apology("Cannot handle fractional values", 400)
        if shares < 0:
            return apology("Please enter a positive integer", 400)

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = cash[0]['cash']
        print(cash)
        symbol = lookup(symbol)
        if not cash > symbol['price'] * shares:
            return apology("You don't have sufficient funds", 400)

        db.execute("INSERT INTO transactions (id, symbol, buy_price, quantity, action) VALUES (?, ?, ?, ?, ?)",
                   session["user_id"], symbol['symbol'], symbol['price'], shares, "buy")
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash -
                   (shares * symbol['price']), session["user_id"])
        print(type(symbol['price']))
        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    history = db.execute("SELECT * FROM transactions")
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Please enter a symbol name", 400)
        if not lookup(request.form.get("symbol")):
            return apology("Ticker invalid", 400)
        symbol = []
        symbol.append(lookup(request.form.get("symbol")))
        # if isspace(symbol[0]):
        #     return apology("Ticker invalid", 400)
        print(symbol)
        return render_template("quoted.html", symbols=symbol)

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("Please enter username", 400)
        if not request.form.get("password") or not request.form.get("confirmation"):
            return apology("Please enter a password", 400)
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get(
                "username"), generate_password_hash(request.form.get("password")))
            if request.form.get("password") != request.form.get("confirmation"):
                return apology("passwordd mismatch", 400)
            return redirect("/login")
        except ValueError:
            return apology("username already taken please try another", 400)
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_stocks = db.execute(
        "SELECT DISTINCT(symbol), SUM(quantity) as 'shares' FROM transactions WHERE id = ? GROUP BY symbol", session["user_id"])
    # user_stocks = db.execute("SELECT DISTINCT(symbol) FROM transactions WHERE id = ?", session["user_id"])
    symbols = []
    shares = []

    if request.method == "POST":
        for stock in user_stocks:
            symbols.append(stock['symbol'])
            shares.append(stock['shares'])
        if not request.form.get("symbol") in symbols:
            return apology("Trying to be smart huh", 400)
        symbol = request.form.get("symbol")
        share = request.form.get("shares")
        idx = symbols.index(symbol)
        print(shares[idx])
        try:
            share = int(share)
        except ValueError:
            return apology("Not valid quantity", 400)
        if not share or share <= 0 or share > shares[idx]:
            return apology("Enter valid shares", 400)
        current_info = lookup(symbol)
        db.execute("INSERT INTO transactions(id, symbol, buy_price, quantity, action) VALUES (?, ?, ?, ?, ?)",
                   session["user_id"], symbol, current_info['price'], -abs(share), "sell")
        sell_value = share * current_info['price']

        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", sell_value, session["user_id"])
        if shares[idx] == share:
            db.execute("DELETE FROM transactions WHERE symbol = ?", symbol)
        return redirect("/")
    return render_template("sell.html", stocks=user_stocks)
