# Pokemon Red

## Description

Pokemon Red, is a project, i'm currently working on to learn C by making a game engine that will hopefully run a Pokemon red like game.


## Project Usage

This project will be used to learn how C and CSFML work.

## TODO

#### Make the camera system
#### Make a 2d map system
#### Make a user that can walk around

## Commit Rule:

### [*\<commit_type\>*] - *\<commit_message\>*.

### ADD:
Indicate that a feature has been added to the project.

### UPDATE:
Indicate that a feature was updated

### REMOVE:
Indicate that a feature has been removed from the project. (Should explain why)

### FIX:
Indicate that a feature was fixed. (Should explain what the issue was and how the fix happened)

### EDIT:
Indicate that a feature has been edited. (Should explain why and how)

### MERGE
Indicate that a merge has happend.

### FIRST
The first commit of the project.

## Map system:

#### While getting the map we don't really care about formatting beacause we only need the data inside () to be correct.
The parsing is just a basic add inside a single string and next parsing the data. The biggest rule is to follow the {} && [] && () rule.

#### You replace [data_name] with the required data.  
Ex:  
[MAP_ID] -> 5

#### Now to create a map you need to follow the next format:
```
MAP:[MAP_ID]{
    ([POS_X];[POS_Y];[TILE_ID])([POS_X];[POS_Y];[TILE_ID])
    ([POS_X];[POS_Y];[TILE_ID])
    Text([POS_X];[POS_Y];[TILE_ID]) ([POS_X];[POS_Y];[TILE_ID])
}
```
#### Here and Example for map: 
```
MAP:1{
    (1;1;5)(1;2;5)(1;3;5) Here i
    (2;1;5)(2;2;5)(2;3;5) can add
    some (3;1;5)(3;2;5)(3;3;5) comment if i want to
}
```

But you can also do it like this:
```
MAP:1{  
(1;1;5)(1;2;5)(1;3;5)   
(2;1;5)(2;2;5)(2;3;5)   
(3;1;5)(3;2;5)(3;3;5)
}
```

Or like so:
```
MAP:1{(1;1;5)(1;2;5)(1;3;5)(2;1;5)(2;2;5)(2;3;5)(3;1;5)(3;2;5)(3;3;5)}
```

Value table for the variable inside map.
```
[MAP_ID]    +-> [UNSIGNED BYTE]
[POS_X]     |-> [SHORT]
[POS_Y]     |-> [SHORT]
[TILE_ID]   +-> [UNSIGNED BYTE]
```

Some explenation about the variable.
```
[MAP_ID]    [UNSIGNED BYTE]     +-> The map id.
[POS_X]     [SHORT]             |-> The position of the tile in x cordinates.
[POS_Y]     [SHORT]             |-> The position of the tile in y cordinates.
[TILE_ID]   [UNSIGNED BYTE]     +-> The tile id to use at those cordinates.
```

Cool, now lets see how to create a tile.
Creating a tile is exactly the same process but with the following format:

```
TILE:[TILE_ID][FILE_PATH]{
    [STATE_ID][
        ([SPRITE_X][SPRITE_Y][DURATION])([SPRITE_X][SPRITE_Y][DURATION])
    ]
    [STATE_ID][
        ([SPRITE_X][SPRITE_Y][DURATION])([SPRITE_X][SPRITE_Y][DURATION])
    ]
}
```

Some explenation about the variable.
```
[TILE_ID]   [UNSIGNED BYTE]     +-> The Tile id.
[STATE_ID]  [UNSIGNED BYTE]     |-> The configuration to use a an x state id.
[FILE_PATH] [STRING]            |-> The path to the tile texture file.
[SPRITE_X]  [SHORT]             |-> The sprite x inside the texture.
[SPRITE_X]  [SHORT]             |-> The sprite y inside the texture.
[DURATION]  [SHORT]             +-> The duration before going to the next sprite of the texture
```