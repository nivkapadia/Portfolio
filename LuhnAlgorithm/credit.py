from cs50 import get_int


def main():
    while True:
        n = get_int("Enter credit card number: ")
        if n > 0:
            break

    # count the number of digits
    digits = len(str(n))

    # get alternate digit and store it in a list
    alDigits = alternateDigit(n)
    otDigits = otherDigits(n)

    # multplying every alternate digit by 2
    for i in range(len(alDigits)):
        alDigits[i] = alDigits[i] * 2
        while len(str(alDigits[i])) > 1:
            alDigits[i] = int(alDigits[i] % 10) + int(alDigits[i] / 10)
            if len(str(alDigits[i])) == 1:
                break

    ccSum = sum(alDigits) + sum(otDigits)
    printResult(n, ccSum)


# gets every alternate digit starting from second last
def alternateDigit(n):
    alternateDigit = []
    tmp = int(n / 10)
    while tmp != 0:
        alternateDigit.append(tmp % 10)
        tmp = int(tmp / 100)
    return alternateDigit


# gets all the other digits
def otherDigits(n):
    otherDigits = []
    while n != 0:
        otherDigits.append(n % 10)
        n = int(n / 100)
    return otherDigits


def starts_with(n):
    length = len(str(n)) - 2
    twoDigits = int(n / (10**length))
    return twoDigits


def printResult(n, ccSum):
    if ccSum % 10 == 0:
        if (starts_with(n) == 34 or starts_with(n) == 37) and len(str(n)) == 15:
            print("AMEX")
        elif starts_with(n) in range(51, 56) and len(str(n)) == 16:
            print("MASTERCARD")
        elif (int(starts_with(n) / 10)) == 4 and (
            len(str(n)) == 13 or len(str(n)) == 16
        ):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()
