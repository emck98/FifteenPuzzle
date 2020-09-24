% find the optimal number of moves to solve a 'fifteen puzzle'
% Moves are represented by:
    % 0: UP
    % 1: RIGHT
    % 2: DOWN
    % 3: LEFT

solve(Board, N) :-
        length(Moves, N),
        fd_domain(Moves, 0, 3),
        length(Board, LB),
        Delta * Delta #= LB,
        sorts(Moves, Board, Delta),
        fd_labeling(Moves).


% IS_INC: check that B is the sequence 1, ..., len(B)-1, 0
is_inc([0], _).
is_inc([X|B], X) :- Y #= X + 1, is_inc(B, Y).


% SORTS: check that the sequence of moves [X|M] sorts B
% all moves accounted for
sorts([], B, _) :- is_inc(B, 1).
% next move is UP
sorts([0|M], B0, D) :-
        up(B0, D, BF),
        sorts(M, BF, D).
% next move is RIGHT
sorts([1|M], B0, D) :-
        right(B0, D, BF),
        sorts(M, BF, D).
% next move is DOWN
sorts([2|M], B0, D) :-
        down(B0, D, BF),
        sorts(M, BF, D).
% next move is LEFT
sorts([3|M], B0, D) :-
        left(B0, D, BF),
        sorts(M, BF, D).


% MOVEMENT FUNCTIONS: BF results from a move *FN* on B0 with a 0 at N and length D^2
up(B0, D, BF) :-
        nth(N, B0, 0),
        Delta_N #= N - D,
        move(B0, N, Delta_N, BF).
right(B0, D, BF) :-
        nth(N, B0, 0),
        Delta_N #= N + 1,
        move(B0, N, Delta_N, BF).
down(B0, D, BF) :-
        nth(N, B0, 0),
        Delta_N #= N + D,
        move(B0, N, Delta_N, BF).
left(B0, D, BF) :-
        nth(N, B0, 0),
        Delta_N #= N - 1,
        move(B0, N, Delta_N, BF).


% MOVE: check that BF is given by a move of the zero from N to Delta_N
move(B0, N, Delta_N, BF) :-
        nth(Delta_N, BF, 0),
        nth(Delta_N, B0, Y),
        nth(N, BF, Y),
        is_equal_except(B0, BF, N, Delta_N).


% IS_EQUAL_EXCEPT: find list L2 st L2 = L1 except at indeces N1 and N2
% N1 != N2 according to usage
is_equal_except([], [], _, _).
is_equal_except([X|L1], [X|L2], N1, N2) :-
        M1 #= N1 - 1,
        M2 #= N2 - 1,
        is_equal_except(L1, L2, M1, M2).
is_equal_except([_|L1], [_|L2], N1, N2) :-
        N1#=1,
        M2 #= N2 - 1,
        fd_max_integer(N),
        is_equal_except(L1, L2, N, M2).
is_equal_except([_|L1], [_|L2], N1, N2) :-
        N2#=1,
        M1 #= N1 - 1,
        fd_max_integer(N),
        is_equal_except(L1, L2, M1, N).
is_equal_except([_|L1], [_|L2], N1, N2) :-
        N1#=1 #/\ N2#=1,
        fd_max_integer(N),
        is_equal_except(L1, L2, N, N).
