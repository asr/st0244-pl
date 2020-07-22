# The dissambler library is available from
# https://kentdlee.github.io/JCoCoPages/_build/html/index.html.
from disassembler import *
import sys

def main():
    x = 5
    y = 6
    z = x+y
    print(z)

if len(sys.argv) == 1:
    main()
else:
    disassemble(main)
