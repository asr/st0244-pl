
% From Kent D. Lee (2017), Foundations of Programming Languages, 2nd
% ed.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% append(X, Y, Z): Appends the list Y to the list X and puts the
% result in the list Z, ie.
%
% append([1,2], [3,4], Z).
% Z = [1,2,3,4].
%
% Note that `append` is a recursive relation.
append([], Y, Y).
append([H | T1], L2, [H | T3]) :- append(T1, L2, T3).

% Examples
% append([1,2], [3,4], Z).
% append(X, [3,4], [1,2,3,4]).
% append([1,2], Y, [1,2,3,4]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% X is a sublist of Y.
%
% "X is a sublist of Y if you can append something on the front of X to
% get L and something else on the end of L to get Y." (p. 283).

sublist(X,Y) :- append(_, X, L) , append(L, _, Y).

% Examples
% sublist([1], [1,2]).
% sublist([2], [1,2]).
% sublist([], [1,2]).
% sublist([1,2], [1,2]).
% sublist(X, X).
