
import disassembler
import sys

def main():
    x = 5
    y = 6
    z = x+y
    print(z)

if len(sys.argv) == 1:
    main()
else:
    disassembler.disassemble(main)
