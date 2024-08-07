
program P;

{ State (global variable) }
var s : integer;

{ The function `f` changes the state, i.e. the global variable. }
function f(a : integer) : integer;
begin
   s := 2;
   f := a;
end;

{ The function `g` depends of the state, i.e. of the global variable. }
function g(b : integer) : integer;
begin
   g := s + b;
end;

begin
   s := 0;

   // The expressions `f(3) + g(4)` and `g(4) + f(3)` are not equals.
   writeln(g(4) + f(3));
   writeln(f(3) + g(4));
end.
