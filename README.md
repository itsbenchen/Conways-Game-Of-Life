# Conway's Game Of Life
## ICS 53L Course Project (Extra Credit)

### Overview of Game:
  This is a C implementation of Conway's Game of Life, which is celluar automation created by John Conway in 1970.
  The game begins with an initial state (2-D orthogonal grid) and infinitely transitions to the next state based on a set of rules. 

#### Conway's Game of Life Rules:

  Each cell is either in the alive or dead state. 

  Each cell's state in the transition is determined by its 8 neighbors around the cell.
    1. If an alive cell has less than 2 ALIVE neighbors, it dies.
      (Under population)
    2. If an alive cell is with 2 or 3 neighbors, it stays ALIVE.
      (Lives on)
    3. if an alive cell is with more than three ALIVE neighbors, it dies.
      (Overpopulation)
    4. Any dead cell is with 3 ALIVE neighbors will become alive too.
       (Reproduction)

### What does this program do?

The program creates a random grid and applies the game's rule to that grid. 
The size of the grid can be changed by changing the pre-defined values "ROWS" and "COLUMNS" at the top of the code file.
Alternatively, you can define your own grid and place it into the main() function instead of the initialized, random gameBoard.
