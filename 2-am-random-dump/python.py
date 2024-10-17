# function that will take grades as input and output if pass or failed
def process_grades(grades):
    # passing_count will keep a track of subjects that the student passed in
    passing_count = 0
    # a for loop to check each grade in the tuple
    for grade in grades:
        # a conditional if statement that verifies if grade is above passing or not and also increases pass count if it is indeed above passing
        if grade > 50:
            print(f"Passing Grade: {grade}")
            passing_count += 1
        # When if condition is not staisfied it will execute this else statement.
        else:
            print(f"Failing Grade: {grade}")
    # returns the integer - passing count when this function has finished it's job.
    return passing_count

# the main function that will use process_grades function and print the output
def run():
    # Tuple of 7 grades
    grades_tuple = (60, 45, 75, 30, 85, 50, 65)

    #calling the function process_grades to get the pass count.
    passing_count = process_grades(grades_tuple)

    print(f"\nTotal Passing Grades: {passing_count}")

run()
