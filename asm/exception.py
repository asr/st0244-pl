import disassembler
import sys

# Without exception handling.
# def main():
#     x = float(input("Enter a number: "))
#     y = float(input("Enter a number: "))
#     z = x/y
#     print(x, "/", y, "=", z)

# With exception handling using the `try-except` statement.
def main():
    try:
        x = float(input("Enter a number: "))
        y = float(input("Enter a number: "))
        z = x / y
        print(x, "/", y, "=", z)

# Errors that could occur in the above code would be a conversion error for
# either of the two floating point number conversions or a division by zero
# error.
    except Exception as ex:
        print(ex)

if len(sys.argv) == 1:
    main()
else:
    disassembler.disassemble(main)
