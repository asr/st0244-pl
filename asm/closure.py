import disassembler
import sys

# The `main` function calls the `f` function which returns the `g`
# function.  The `g` function returns `x`.
#
# The `g` function is defined inside the `f` function which is defined
# inside the `main` function.
def main():
    x = 10
    def f(x):
        def g():
            return x
        # Notice that the `f` function does not call the `g` function,
        # but returns it.
        return g
     # The extra set of parens after the function call `f(3)` calls the
     # function `g`.
    print(f(3)())

if len(sys.argv) == 1:
    main()
else:
    # The disassembler is called on the top-level function `main`
    # because the disassembler automatically disassembles any nested
    # functions when disassembling a function.
    disassembler.disassemble(main)
