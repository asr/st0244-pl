{ Tested with Free Pascal Compiler version 3.0.0+dfsg-2 [2016/01/28]. }

{ Adapted from Fig. 5.1 in Kent D. Lee (2017), Foundations of }
{ Programming Languages, 2nd ed. }

{ Addition is no commutative in Pascal! }

program P;

{ Global variable }
var b : integer;

function a() : integer;
begin
   b := b + 2;
   a := 5;
end;

begin
   b := 10;

   { Prints 17 }
   { writeln(a() + b); }

   { Prints 15 }
   { writeln(b + a()) };
end.
