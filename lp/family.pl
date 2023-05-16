
%% Adapted from Fig. 7.2 in Kent D. Lee (2017), Foundations of
%% Programming Languages, 2nd ed.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Gender

female(addie).
female(anne).
female(inger).
female(gerry).
female(michelle).
male(bruce).
male(esther).
male(gary).
male(fred).
male(johan).
male(john).
male(johnhs).
male(kenny).
male(kent).
male(lars).
male(lawrence).
male(mads).
male(stephen).
male(sophus).
male(sophusw).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Family tree.

parent(addie, gary).
parent(anne, gary).
parent(gary, kent).
parent(gary, stephen).
parent(gary, anne).
parent(gerry, kent).
parent(fred, sophusw).
parent(fred, lawrence).
parent(fred, kenny).
parent(fred, esther).
parent(inger, sophusw).
parent(johan, sophus).
parent(johnhs, fred).
parent(lars, johan).
parent(lars, mads).
parent(mads, johnhs).
parent(sophusw, gary).
parent(sophusw, john).
parent(sophusw, bruce).
parent(john, michael).
parent(john, michelle).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Predicates.

father(X,Y) :- parent(X,Y), male(X).
mother(X,Y) :- parent(X,Y), female(X).
