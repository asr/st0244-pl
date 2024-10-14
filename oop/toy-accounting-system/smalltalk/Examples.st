" Examples `Account` class"

a := Account new.
a deposit: 125.
a deposit: 20.
a spend: 10.
a printNl.

s := Savings new.
s deposit: 125.
s deposit: 20.
s spend: 10.
s printNl.

" Examples `Checking` class"

c := Checking new.
c deposit: 250.
c newChecks: 100 count: 50.
c writeCheck: 32.
c printNl.
c printChecks.
