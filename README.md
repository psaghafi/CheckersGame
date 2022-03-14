# CheckersGame
#   The Game of FlipFlop is a strategy oriented board game with the following rules:
1. The game begins on a board of N squares by N squares. N must be at least 8 and N must be even,
2. The game is played by two players using game pieces that are placed on the squares of the board.
    One player uses white game pieces; the other player uses black game pieces.
3. White moves first.
4. The game ends when of the conditions below is true:
(a)The black player has taken N2/2 turns.
 (b)When a player plays 0 game pieces and their opponent then also plays 0 game pieces. 
5. The initial board will look like this:
6. When a player places a game piece on the board it MUST trap at least one of their opponent’s
game pieces. To understand when a piece is trapped we must think of the board in terms of ‘lines’.
A line must be straight, but may be horizontal, vertical or diagonal.

(a)To trap an opponent’s piece there must be one of your pieces on each side of the piece
within a particular line. For example placing a white piece on the blue square in the board
above would trap one black piece between two white pieces in a horizontal line.

(b)You may trap any number of your opponent’s pieces in a single move. To trap more than one
of your opponent’s pieces in the same line your opponent must have more than one
adjacent piece in that line. In some cases it may be possible to trap opponent’s pieces along
more than one line with a single move.

Some examples are shown on the board below. If it is white’s move, the X’s show two
squares where a white piece could be placed to trap two black pieces in a row along a
diagonal line. If it is black’s move the Y shows where a black piece could be placed to trap 4
white pieces in a horizontal row. An example of this is shown on the board below. Assume
that it is black’s turn and black has chosen to place a black piece on the square indicated by
the Z. This move traps 1 piece along a vertical line and 1 piece along a diagonal line. 

7. When a player makes a move they must place zero, one, or two pieces on the board. Each piece
placed on the board must trap an opponent’s game piece.

(a) If it is not possible to trap an opponent’s game piece along a horizontal line or along a
vertical line (your program needs to check this and end the turn if necessary) then the player
places zero game pieces on the board and ends their turn.

(b) If it is possible to trap an opponent’s game piece along a horizontal line or along a vertical
line then the player must try to play their first game piece. If the player does not trap two or
more of their opponent’s pieces when they play their first game piece the player’s turn is
over.

(c) If the player traps two or more of their opponent’s game pieces when they place their first
game piece on the board then the player may choose to place a second game piece on the
board. If the second game piece is placed it MUST be placed so that it traps at least one of
the opponent’s game pieces along a diagonal line. 

8. Immediately after a game piece has been placed on the board ALL trapped opponent’s game pieces
will be “captured”. This includes game pieces trapped in ALL possible directions (horizontally,
vertically, or diagonally). When a game piece is captured the color of the game piece is changed. In
the examples above the black game pieces trapped by placing the new white game pieces on one X
would become white game pieces or the white game pieces trapped by the new black game piece
places on the Y would be changed to black game pieces. 
