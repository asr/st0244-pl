
% From Kent D. Lee (2017), Foundations of Programming Languages, 2nd
% ed.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Length of a list.

len([], 0).
len([ _ | T ], N ) :- len(T, M), N is M + 1.
