import disassembler
import sys

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

def main():
    print(factorial(5))

if len(sys.argv) == 1:
    main()
else:
    # We also need to disassembler the `factorial` function.
    disassembler.disassemble(factorial)
    disassembler.disassemble(main)
