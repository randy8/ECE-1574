# Minesweeper
This implementation relies on an 8x8 array to store the location of bombs on the board and reads in a series of commands from a file, mimicking the traditional minesweeper gameplay but instead using a hard-coded board. The game is over when all the board is cleared such that no bombs are touched (W) or if a bomb is touched (L). There will be three main commands that will be read which are load, touch, and display with descriptions as follows:
```
load - reads the board filename and opens the file. The board will be shown below, but it will be in an 8x8 grid periods and asterisks. A period represents a blank space while an asterisk represents a bomb.

touch - will be followed by two integers. The integers represent an x and y coordinate on the board where the player would like to touch. If the coordinates do not fall within the confines of our grid, nothing is done. Only one space is revealed at a time, as opposed to an actual game in which a large area (without bombs) may be revealed from a single touch.

display - the display command will display the current view of the board.  Any touched spaces will show how many bombs they are next to.  '0' will be used for blanks that do not touch any spaces.  
The final board will have the following symbols:
. - spaces that has not been touched.
# - the number (actual integer value, not the pound symbol) will indicate how many bombs this square is touching.  
* - this is an exploded bomb.  If a bomb is touched, this will be shown in the final board.
@ - this is an unexploded bomb.  If bombs are not touched, this will be shown in the final board.
```
The output will be generated upon running the program.
## Compile/Run 
### Linux:
```
g++ -std=c++11 minesweeper.cpp -o ms
./ms
```
### Windows (e.g. PowerShell):
```
cl /Ehsc /c minesweeper.cpp
link /out:ms.exe minesweeper.obj
./ms.exe
```
