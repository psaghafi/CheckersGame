# Your function InitializeBoard should
1. Have the prototype
bool InitializeBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard );

2. InitializeBoard will fail (return false) if the numRowsInBoard is out of range or if an unallocated
dynamic array is passed to the function.

3. The meanings of the values that will be placed into the FlipFlopBoard when it is initialized are
a) 0 in an element of FlipFlopBoard indicates there is no game piece on the square
b) 1 in an element of FlipFlopBoard indicates there is a white game piece on the square
c) 2 in an element of FlipFlopBoard indicates there is a black game piece on the square
4. Begin by initializing the FlipFlopBoard to be an empty board
5. Place the first four tiles on the center 4 squares of the board. (see the example in the example of the
rules at the start of this lab)

6. For example after initialization a 8X8 or 10X10 board would have the following values in the array
FlipFlopBoard

8X8 BOARD

0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0

0 0 0 1 2 0 0 0

0 0 0 2 1 0 0 0

0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0

OR

10X10 BOARD

0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0

0 0 0 0 1 2 0 0 0 0

0 0 0 0 2 1 0 0 0 0

0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0

# Your function DisplayBoard should
1. Have the prototype
bool DisplayBoard( int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

2. The meanings of the values tin the FlipFlopBoard are
(a) 0 in an element of FlipFlopBoard indicates there is no game piece on the square
(b) 1 in an element of FlipFlopBoard indicates there is a white game piece on the square
(c) 2 in an element of FlipFlopBoard indicates there is a black game piece on the square

3. Step through the FlipFlopBoard array
(a) For the nonzero elements of the FlipFlopBoard
i. Print a B if a there is a black game piece on the square (FlipFlopBoard element = 2)
ii. Print a W if there is a white game piece on the square (FlipFlopBoard element =1)

(b) For zero elements (empty squares) of FlipFlopBoard print the square number
i. An example of the square numbers for a 8x8 board is given above (in the discussion of
the main program), here is an additional example for a 10x10 board

0 1 2 3 4 5 6 7 8 9

10 11 12 13 14 15 16 17 18 19

20 21 22 23 24 25 26 27 28 29

30 31 32 33 34 35 36 37 38 39

40 41 42 43 44 45 46 47 48 49

50 51 52 53 54 55 56 57 58 59

60 61 62 63 64 65 66 67 68 69

70 71 72 73 74 75 76 77 78 79

80 81 82 83 84 85 86 87 88 89

90 91 92 93 94 95 96 97 98 99

c) Each number or character should be printed in a field 4 characters wide

# Your function PlacePiece should
1. Have the prototype
bool PlacePiece(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard,
int player, int squarePlayed, int whichPiece, int& numberCaptured );

2. Begin at a square indicated by the squarePlayed (the place the player is trying to put a piece this
turn). The value of squarePlayed will be the square number as displayed in the DisplayBoard
function. The value of squarePlayed should be translated to the location in the FlipFlopBoard.

3. If whichPiece indicates the first piece is being played, then make four calls to CheckLine for
horizontal and vertical lines.

(a) If none of the the four calls to CheckLine for horizontal and vertical lines returns true then the
move is not a valid move
i. Print a line of text to the screen that says
Illegal move
ii. Return false

(b) If any of the four calls to CheckLine returns true then the chosen square is a square into which
the piece may be placed.
i. Place the piece on the board
ii. Determine how many of the opponent’s game pieces will be captured. It is possible
the trap opponent’s pieces in more than one direction when placing a single piece on
the board. To determine which pieces are captured you must consider all directions
(including diagonal horizontal and vertical directions). The number captured pieces
sent to the calling program includes all pieces captured in all directions.
iii. Change the colour of all the captured pieces
iv. Print a line of text to the screen that says either
White has placed the first piece
Black has placed the first piece
v. return true

4. If whichPiece indicates the second piece is being played then make four calls to CheckLine for
diagonal lines

(a) If none of the the four calls to CheckLine for diagonal lines returns true then the move is not a
valid move
i. Print a line of text to the screen that says
Illegal move
ii. Return false

(b) If any of the calls to CheckLine returns true then the chosen square is a square into which the
piece may be placed.
i. Place the piece on the board
ii. Determine how many of the opponent’s game pieces will be captured.
iii. Change the colour of all the trapped pieces
iv. Print a line of text to the screen that says either
White has placed the second piece
Black has placed the second piece
v. Return true

# The function IsThisMoveValid
1.Has the prototype
bool IsThisMoveValid( int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
int numRowsInBoard, int player, int squarePlayed, int whichPiece );

2. For the square squarePlayed find the x and y coordinates in the FlipFlopBoard
3. Determine from whichPiece if this a a piece being played in the first turn or the second turn

i. If the piece is being played in the first piece played in a turn, call CheckLine for each of the four horizontal
and vertical directions.

(a) If none of the four calls to CheckLine then return false

(b) If any of the four calls to CheckLine return true then return true

ii. If the piece is being played in the second piece played in a turn then call CheckLine for each of the four
diagonal directions
(a) If none of the four calls to CheckLine then return false

(b) If any of the four calls to CheckLine return true then return true

# The function IsThisMoveValid
1. Has the prototype
bool IsAnyMoveValid(( int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
int numRowsInBoard, int player, int whichPiece);

2. Checks every possible location in the FlipFlopBoard to see if there is a valid move starting at that location.

3. Returns true as soon as it finds a location that can be the start of a valid move

4. Returns false if there are no locations that can be used as the start of a valid move.
You should either call IsThisMoveValid for each location in the FlipFlopBoard until a location returns 0. Or
implement the description of IsThisMoveValid within loops in this function.

# The provided function CheckLine
1. Has the prototype
bool CheckLine( int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard,
int player, int squarePlayed, int xDirection, int yDirection, int& numCaptured );

2. Begins at a square indicated by the squarePlayed (the place the player is trying to put his piece this
turn). The value of squarePlayed will be the square number as displayed in the DisplayBoard
function. The value of squarePlayed should be translated toan the location in the FlipFlopBoard
array (the indices x and y in FlipFlopBoard[x][y] ).

3. The values of xDirection and yDirection will indicate which direction to check for possible
‘trapping’ of opponents pieces. If the piece is being placed at location (x,y) in the board (row x,
column y) then we can check in any one of eight directions. If xDirection=1 and yDirection=0 you
are checking along a horizontal line toward the right. If xDirection = 0 yDirection = -1 you are
checking along a vertical line to the bottom. If xDirection = -1 and yDirection=1 then your are
checking along a diagonal line upwards and to the left. Etc.

4. The value of player is 1 if this is a white player’s turn, and 2 if this is a black player’s turn.

5. If the first square in the selected direction is empty, return false

6. If the first square in the selected direction contains one of the player’s pieces, return false

7. If the first square int the selected direction contains one of the opponent’s pieces then we must
consider addition squares further along the line in the same direction. For each successive square
along the line in the direction being considered

(a) if the square is empty return false.

(b) If the square contains an opponent’s piece continue to the next square along the line

(c) If you reach the edge of the board without finding one of the player’s pieces return false

(d) If the square contains one of the player’s pieces then return true
