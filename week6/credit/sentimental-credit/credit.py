from cs50 import *


def main():
    credit = int(input("Number: "))
    tmp = credit
    mult = 0
    sum = 0

    if credit < 9000000000:
        print("INVALID")
        exit()

    tmp = credit // 10

    while tmp > 0:
        mult = tmp % 10
        mult *= 2
        print(mult)
        if mult >= 10:
            while mult > 0:
                sum += mult % 10
                mult //= 10
        else:
            sum += mult
        tmp //= 100

    tmp = credit

    while tmp > 0:
        mult = tmp % 10
        sum += mult
        tmp //= 100

    while credit > 100:
        credit //= 10

    if 0 == sum % 10:
        if 4 == credit or (40 <= credit and 50 > credit):
            print("VISA")
        elif 34 == credit or 37 == credit:
            print("AMEX")
        elif 51 <= credit and credit <= 55:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()
