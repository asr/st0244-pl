import disassembler
import sys

def main():
    x   = input("Enter a list: ")
    lst = x.split()
    for b in lst:
        print(b)

if len(sys.argv) == 1:
    main()
else:
    disassembler.disassemble(main)
