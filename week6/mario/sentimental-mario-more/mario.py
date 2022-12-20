from cs50 import get_int


def main():
    height = get_height()
    for i in range(height):
        for j in range(height - i - 1):
            print(" ", end="")
        for k in range(i+1):
            print("#", end="")
        print("  ", end="")
        for l in range(i+1):
            print("#", end="")
        print("")


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                break
        except ValueError:
            print("That's not an integer!")
    return n


main()