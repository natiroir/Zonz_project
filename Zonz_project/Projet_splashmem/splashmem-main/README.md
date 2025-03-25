# Splashmem


Splashmem is a basic education game, where for program compete to mark the most memory addresses.

Each player is a share object lib, which is interrogated each turn to get the action to be realize.

The source could is mainly made for Linux, be can easly be used on Windows or MacOS 

**NOTE**: as this repo is for student, the code is incomplete.

# Depends 

SDL2 development must be installed on your system

# Compile with Cmake

```

$ cmake -Bbuild -H.  
$ cmake --build build/

```
can add -DCMAKE_BUILD_TYPE=debug for debug.



# Compile with make

```
make -f old.makefile
```


# Usage
The ```.so``` files (libraries) are passed as parameters to the application for example:

```
./splashmem ./p1.so ./p2.so ./p3.so ./p4.so
```

# Rules 

Creation of a multiplayer game, with a maximum of 4 players. Each player is a program whose goal is to fill memory squares. The program/player that fills the most squares with its credits wins the game.

Each player have 9000 credits.

| Code | Cost | Action|
|------|:----:|:------|
|ACTION_MOVE_L| 1 | Move player of the block |
|ACTION_MOVE_R| 1 | Move player of the block |
|ACTION_MOVE_U| 1 | Move player of the block |
|ACTION_MOVE_D| 1 | Move player of the block |
|ACTION_DASH_L | 10 | Move player of 8 block in one direction |
|ACTION_DASH_R | 10 | Move player of 8 block in one direction |
|ACTION_DASH_U | 10 | Move player of 8 block in one direction |
|ACTION_DASH_D | 10 | Move player of 8 block in one direction |
|ACTION_TELEPORT_L | 4 | Teleport player 8 blocks away |
|ACTION_TELEPORT_R | 4 | Teleport player 8 blocks away|
|ACTION_TELEPORT_U | 4 | Teleport player 8 blocks away|
|ACTION_TELEPORT_D | 4 | Teleport player 8 blocks away|
|ACTION_SPLASH |8 | Marque toute les cases autour du joueur |
|ACTION_BOMB |9 | Place une bombe qui marque 9 cases et qui ce déclenche après 5 tours |
|ACTION_STILL |1 | Pas d'action |


As soon as a player lands on a square, it is automatically marked.

The game board size is 100 squares by 100 squares.
Each player starts at the same distance.
When a player exceeds an edge, they are sent back to the opposite side (Pacman effect).

Each player-program has ```x,y``` coordinates, with the coordinate ```(0,0)``` at the top-left corner of the playing area.


# Objective

Complete the game code: 
- Take the dynamic libraries as parameters of the program. Attach the library to a player in the engine. 
- Retrieve the player's actions (using the library).
- Alter the player's properties based on the action and draw on the map.
- Deduct the player's credits.


# Other information 

The field get_action is a function pointer that returns a char and takes no parameters.

The function:
```char get_action(void); ```

The function pointer declaration in the structure t_player:
```char (*get_action)(void);```

These are accessible through an array of structure pointers declared in the file ```world.h``` and accessible anywhere:

```extern t_player *players[];```

The size of the player array is ```MAX_PLAYERS``` (equal to 4).


## parameters 
The parameters correspond to the file path of the dynamic library. This path will be useful for the ```dlopen()``` function.


The ```so_handle``` field in the t_player structure will be filled with the reference resulting from the ```dlopen()``` function.

The ```dlopen()``` function allows opening a dynamic library. Once opened, the library's code is now available.

The ```dlsym()``` function allows retrieving a reference to a function present in the library.
In our case, the library contains a ```get_action()``` function, and the reference to this function should be stored in the get_action field of the ```t_player``` structure.
