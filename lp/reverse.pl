
% From Kent D. Lee (2017), Foundations of Programming Languages, 2nd
% ed.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% append(X, Y, Z): Appends the list Y to the list X and puts the
% result in the list Z, ie.
%
append([], Y, Y).
append([H | T1], L2, [H | T3]) :- append(T1, L2, T3).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reverse of a list.

% Reverse of a list using append.
reverse([], []).
reverse([ H | T ], R) :- reverse(T, RT), append(RT, [H], R).

% Reverse of a list using the accumulator pattern.
rev([], Acc, Acc).
rev([ H | T ], Acc, R) :- rev(T, [ H | Acc ], R).
reverseAP(L,R) :- rev(L, [], R).
