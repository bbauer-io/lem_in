# lem_in
This program interprets a map file placed on the standard input, then finds the shortest route between the rooms. Then it navigates a number of 'ants' from the start to the exit and describes their path. Only one ant may be in a room at any time, except for the ##start and ##end rooms.

Maps look like this:
```
# Lines starting with a single '#' are comments and will be ignored.
# The line below defines how many "ants" need to get from ##Start to ##End.
5
# The line below designates the starting point for the ants.
##start
1 23 3
2 16 7
# These are rooms, the first number is the name (pretty boring names here..).
# The second two numbers are x, y coordinates.
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
# The line below designates the ending point for the ants.
##end
0 9 5
# All the lines below describe the connections between the rooms above.
0-4
0-6
1-3
4-3
5-2
3-5
4-2
2-1
7-6
7-2
7-4
6-5
```

Usage:
```
> make
> ./lem-in < testmap.lemin
```

Output:
```
10
##start
0 37 21
1 83 84
2 8 50
3 5 55
4 48 91
5 28 42
6 29 80
7 47 31
8 87 71
##end
9 40 98
0-1
0-7
1-9
2-1
2-5
3-2
3-4
3-7
3-9
4-1
4-2
4-9
5-6
5-8
6-1
6-2
6-4
6-8
7-1
7-2
7-7

Lx0-1
Lx0-9 Lx1-1
Lx1-9 Lx2-1
Lx2-9 Lx3-1
Lx3-9 Lx4-1
Lx4-9 Lx5-1
Lx5-9 Lx6-1
Lx6-9 Lx7-1
Lx7-9 Lx8-1
Lx8-9 Lx9-1
Lx9-9
```

In the output, Ants are numbered in hexadecimal and prefixed with 'Lx'.

"Lx0-3" would be interpreted as "Ant Lx0 moves to room 3".

Each line is one turn. Ants can travel one room per turn.

