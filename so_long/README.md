# so_long
And thanks for all the fish!

## Summary
This project is a very small 2D game.
Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.


## Install
```sh
make         # comfile ./so_long
make bonus   # comfile bonus ./so_long
make clean   # remove temporary files
make fclean  # remove all files
make re      # make fclean and make
```

## Usage
```sh
./so_long map.ber
```

## Game play
### Goal
Collecting all the collections and escaping the map.

### Control
Arrow keys

### Map
`0` : Empty space  
`1` : Wall  
`C` : Collection  
`E` : Exit  
`P` : Start point

#### example 01
```sh
1111111111111111111111111111111111
100000000000000C01001C100000000CE1
10100101001000001110001000CC010101
10100100101010100010010010P0011101
1000C0000C00C0000000000011100000C1
1000011100000000000010000010000001
```

#### example 02
```sh
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
