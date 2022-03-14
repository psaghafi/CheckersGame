#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_ARRAY_SIZE 24
#define MIN_ARRAY_SIZE 8

const int NOPLAYER = 0;
const int WHITEPLAYER = 1;
const int BLACKPLAYER = 2;
const int FIRST_PIECE = 1;
const int SECOND_PIECE = 2;


bool PlacePiece(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed,
	int whichPiece, int& numberCaptured);
bool DisplayBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard);
bool InitialiizeBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard);
bool CheckLine(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed,
	int xDirection, int yDirection, int& numCaptured);
bool IsAnyMoveValid(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int whichPiece);
bool IsThisMoveValid(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int whichPiece);
bool updateBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int checkLineTable[8][3]);
int getBoardSize();
bool firstMove(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int& numCaptured);
bool secondMove(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int& numCaptured);




int main()
{

	int myFlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

	// ADD CODE FOR MAIN FUNCTION HERE
	int flag = 0;
	int numRowsInBoard = 0;
	int player = WHITEPLAYER;
	int whichPiece = FIRST_PIECE;
	bool gameOver = false;
	int squarePlayed = 0;
	int xCoordinate = -1;
	int yCoordinate = -1;
	int numberCaptured = 0;
	char playSecondPiece = 'N';
	int moveCounter = 1;

	numRowsInBoard = getBoardSize();
	InitialiizeBoard(myFlipFlopBoard, numRowsInBoard);
	DisplayBoard(myFlipFlopBoard, numRowsInBoard);


	while (moveCounter < numRowsInBoard*numRowsInBoard &&
		(IsAnyMoveValid(myFlipFlopBoard, numRowsInBoard, WHITEPLAYER, FIRST_PIECE) ||
			IsAnyMoveValid(myFlipFlopBoard, numRowsInBoard, BLACKPLAYER, FIRST_PIECE)
			))

	{
		numberCaptured = 0;
		firstMove(myFlipFlopBoard, numRowsInBoard, player, squarePlayed, numberCaptured);


		if (numberCaptured > 1)
		{
			cout << "Do you wish to play a second piece?  Y/N ";
			cin >> playSecondPiece;
			if (playSecondPiece == 'y'|| playSecondPiece == 'Y') {
				whichPiece = SECOND_PIECE;
				secondMove(myFlipFlopBoard, numRowsInBoard, player, squarePlayed, numberCaptured);
			}
		}
		moveCounter++;
		if (player == WHITEPLAYER)
		{
			player = BLACKPLAYER;
		}
		else
		{
			player = WHITEPLAYER;
		}

		whichPiece = FIRST_PIECE;

		if (!IsAnyMoveValid(myFlipFlopBoard, numRowsInBoard, WHITEPLAYER, FIRST_PIECE) &&
			!IsAnyMoveValid(myFlipFlopBoard, numRowsInBoard, WHITEPLAYER, FIRST_PIECE))
		{
			cout << "White is unable to move " << endl;
			cout << "Black is unable to move " << endl;
			cout << "GAME OVER " << endl;
			cout << "Enter any character to close the game " << endl;
			getchar();
		}
	}

	return 0;
}

/*
This function check if the player can play the first piece by calling function IsAnyMoveValid.
If function IsAnyMoveValid returns false then there is no available move. If there is no available
move print one of the following messages.
White is unable to move
Black is unable to move
But If the player can place their first game piece on the board print one of the following single line
message to the screen:
White takes a turn
Black takes a turn
c) Give the player three attempts to select a legal square to place their first game piece on. If the
player does not select a legal square in three tries he forfeits his turn. If the player forfeits their
turn print one of the following messages
White has forfeited a turn
Black has forfeited a turn
if the first first piece is playable then attempt to place the first piece
by calling function PlacePiece.
If PlacePiece returns false (the requested move is illegal) then print the error message
below
ERROR: illegal move
Try again
Proceed to the next try
If PlacePiece returns true and the first piece captured exactly one opponent’s piece
print the board to the screen using the DisplayBoard funtion
AUTHOR: PARMIDA SAGHAFI
*/

bool firstMove(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int& numberCaptured)
{
	int flag = 0;
	int whichPiece = FIRST_PIECE;
	bool gameOver = false;
	int xCoordinate = -1;
	int yCoordinate = -1;
	string str = " ";
	numberCaptured = 0;

	if (IsAnyMoveValid(FlipFlopBoard, numRowsInBoard, player, whichPiece))
	{
		if (player == WHITEPLAYER)
		{
			cout << "White takes a turn" << endl;
		}
		else
		{
			cout << "Black takes a turn" << endl;
		}
	}
	else
	{
		if (player == WHITEPLAYER)
		{
			cout << "White is unable to move" << endl;
			player = BLACKPLAYER;
		}
		else
		{
			cout << "Black is unable to move" << endl;
			player = WHITEPLAYER;
		}
	}

	flag = 0;
	while (flag <= 3)
	{
		if (flag == 3)
		{
			if (player == WHITEPLAYER)
			{
				cout << "White has forfeited a turn" << endl;
				DisplayBoard(FlipFlopBoard, numRowsInBoard);
				player = BLACKPLAYER;
				break;
			}
			else
			{
				cout << "Black has forfeited a turn" << endl;
				DisplayBoard(FlipFlopBoard, numRowsInBoard);
				player = WHITEPLAYER;
				break;
			}
		}
		cout << "Enter the square number of the square you want to put your first piece on" << endl;

		cin >> str;
		if ((str[0] <= 'z' && str[0] >= 'a') || (str[0] <= 'Z' && str[0] >= 'A'))
		{
			cout << "Error: square chosen not an integer" << endl;
			flag++;
			continue;
		}
		else
		{
			squarePlayed = stoi(str);
		}

		if (squarePlayed < 0 || squarePlayed > numRowsInBoard * numRowsInBoard - 1)
		{
			cout << "ERROR: that square is not on the board." << endl;
			cout << "Try again" << endl;
			flag++;
			continue;
		}
		if (IsThisMoveValid(FlipFlopBoard, numRowsInBoard, player, squarePlayed, whichPiece))
		{
			PlacePiece(FlipFlopBoard, numRowsInBoard, player, squarePlayed, whichPiece, numberCaptured);
			break;
		}
		else
		{
			cout << "ERROR: illegal move" << endl;
			cout << "Try again" << endl;
			flag++;
		}

	}

	xCoordinate = squarePlayed % numRowsInBoard;
	yCoordinate = squarePlayed / numRowsInBoard;
	if (player == WHITEPLAYER && numberCaptured > 0 && whichPiece == FIRST_PIECE)
	{
		cout << "White has placed the first piece" << endl;
		DisplayBoard(FlipFlopBoard, numRowsInBoard);
		cout << "Your first piece captured " << numberCaptured << " opponent's pieces" << endl;
	}
	else if (player == BLACKPLAYER && numberCaptured > 0 && whichPiece == FIRST_PIECE)
	{
		cout << "Black has placed the first piece" << endl;
		DisplayBoard(FlipFlopBoard, numRowsInBoard);
		cout << "Your first piece captured " << numberCaptured << " opponent's pieces" << endl;
	}
	return true;
}

/*
This function will be called whenever the first piece captured more than one opponent’s piece.
If the player does not wish to play a second piece then opponent take a turn.
Otherwise function checks if the player has a legal move (using IsThisMoveValid). If there is no
legal move then opponent take a turn.
The Rules for second move are similar to first move except:
In second move we check diagonally for capturing opponent's pieces.
AUTHOR: PARMIDA SAGHAFI
*/
bool secondMove(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int& numberCaptured)
{
	int flag = 0;
	int whichPiece = SECOND_PIECE;
	bool gameOver = false;
	int xCoordinate = -1;
	int yCoordinate = -1;
	string str;
	numberCaptured = 0;

	if (!IsAnyMoveValid(FlipFlopBoard, numRowsInBoard, player, whichPiece))
	{
		if (player == WHITEPLAYER)
		{
			cout << "White is unable to move" << endl;
			player = BLACKPLAYER;
			return false;
		}
		else
		{
			cout << "Black is unable to move" << endl;
			player = WHITEPLAYER;
			return false;
		}
	}

	flag = 0;
	while (flag <= 3)
	{
		if (flag == 3)
		{
			if (player == WHITEPLAYER)
			{
				cout << "White has forfeited a turn" << endl;
				DisplayBoard(FlipFlopBoard, numRowsInBoard);
				player = BLACKPLAYER;
				break;
			}
			else
			{
				cout << "Black has forfeited a turn" << endl;
				DisplayBoard(FlipFlopBoard, numRowsInBoard);
				player = WHITEPLAYER;
				break;
			}
		}
		cout << "Enter square number of the square you want to put your second piece on" << endl;
		cin >> str;
		if ((str[0] <= 'z' && str[0] >= 'a') || (str[0] <= 'Z' && str[0] >= 'A'))
		{
			cout << "ERROR: square chosen not an integer" << endl;
			flag++;
			continue;
		}
		else
		{
			squarePlayed = stoi(str);
		}

		if (squarePlayed < 0 || squarePlayed > numRowsInBoard * numRowsInBoard - 1)
		{
			cout << "ERROR: that square is not on the board." << endl;
			cout << "Try again." << endl;
			flag++;
			continue;
		}

		xCoordinate = squarePlayed % numRowsInBoard;
		yCoordinate = squarePlayed / numRowsInBoard;

		if (IsThisMoveValid(FlipFlopBoard, numRowsInBoard, player, squarePlayed, whichPiece))
		{
			PlacePiece(FlipFlopBoard, numRowsInBoard, player, squarePlayed, whichPiece, numberCaptured);
			break;
		}
		else
		{
			cout << "ERROR: illegal move" << endl;
			cout << "Try again" << endl;
			flag++;
		}

	}
	if (player == WHITEPLAYER && numberCaptured > 0 && whichPiece == SECOND_PIECE)
	{
		cout << "White has placed the second piece" << endl;
		DisplayBoard(FlipFlopBoard, numRowsInBoard);
		cout << "Your second piece captured " << numberCaptured << " opponent's pieces" << endl;
	}
	else if (player == BLACKPLAYER && numberCaptured > 0 && whichPiece == SECOND_PIECE)
	{
		cout << "Black has placed the second piece" << endl;
		DisplayBoard(FlipFlopBoard, numRowsInBoard);
		cout << "Your second piece captured " << numberCaptured << " opponent's pieces" << endl;
	}
	return true;
}


/*
This function gets the board size entered by the user.
The correct range for board size is 8 <= numRowsInBoard <= 24, numRowsInBoard must be
even. If the board size is not valid one of the following error messages should be printed
ERROR: Board size too large
ERROR: Board size too small
ERROR: Board size odd
ERROR: Board size is not an integer
ERROR: If the USER enters a non-integer charcter
At most the user can try 3 times for input
AUTHOR: PARMIDA SAGHAFI

*/
int getBoardSize()
{
	int flag = 0;
	int numRowsInBoard = 0;
	string str = "";
	while (flag <= 3) {

		if (flag == 3)
		{
			cout << "ERROR: Too many errors entering the size of the board" << endl;
			return 0;
		}

		cout << "Enter the number of squares along each edge of board" << endl;
		cin >> str;

		if ((str[0] <= 'z' && str[0] >= 'a') || (str[0] <= 'Z' && str[0] >= 'A'))
		{
			cout << "ERROR: Board size is not an integer" << endl;
			cout << "8 <= number of squares <= 24" << endl;
			flag++;
			continue;
		}
		else
		{
			numRowsInBoard = stoi(str);
		}

		if (numRowsInBoard % 2 != 0)
		{
			cout << "ERROR: Board size odd" << endl;
			cout << "8 <= number of squares <= 24" << endl;
			flag++;
			continue;
		}
		if (numRowsInBoard > MAX_ARRAY_SIZE)
		{
			cout << "ERROR: Board size too large" << endl;
			cout << "8 <= number of squares <= 24" << endl;
			flag++;
			continue;
		}
		if (numRowsInBoard < MIN_ARRAY_SIZE)
		{
			cout << "ERROR: Board size too small" << endl;
			cout << "8 <= number of squares <= 24" << endl;
			flag++;
			continue;
		}
		break;
	}
	return numRowsInBoard;
}


/*
This function makes a 2D array for the board of the game.
The size of the board is between 8 and 24 and it is even number.
in the middle of the board each player has 2 pieces.
*/
bool InitialiizeBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard)
{
	for (int i = 0; i < numRowsInBoard; i++)
	{
		for (int j = 0; j < numRowsInBoard; j++)
		{
			FlipFlopBoard[i][j] = 0;
		}
	}
	FlipFlopBoard[numRowsInBoard / 2 - 1][numRowsInBoard / 2 - 1] = 1;
	FlipFlopBoard[(numRowsInBoard / 2)][(numRowsInBoard / 2)] = 1;
	FlipFlopBoard[(numRowsInBoard / 2)][numRowsInBoard / 2 - 1] = 2;
	FlipFlopBoard[numRowsInBoard / 2 - 1][(numRowsInBoard / 2)] = 2;

	return true;
}

/*
This function gets the board 2D array and it converts the data to something
that is undestandable.
The meanings of the values in the FlipFlopBoard are
0 in an element of FlipFlopBoard indicates there is no game piece on the square
1 in an element of FlipFlopBoard indicates there is a white game piece on the square
2 in an element of FlipFlopBoard indicates there is a black game piece on the square

0 = EMPTY
1 = WHITE
2 = BLACK
AUTHOR: PARMIDA SAGHAFI

*/

bool DisplayBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard)
{
	for (int i = 0; i < numRowsInBoard; i++)
	{
		for (int j = 0; j < numRowsInBoard; j++)
		{
			if (FlipFlopBoard[i][j] == 0)
			{
				cout << setw(4) << i * numRowsInBoard + j;
			}
			else if (FlipFlopBoard[i][j] == 1)
			{
				cout << setw(4) << "W";
			}
			else if (FlipFlopBoard[i][j] == 2)
			{
				cout << setw(4) << "B";
			}
			else
			{
				cout << "ERROR: Could not print the game board";
				return false;
			}
		}
		cout << endl;
	}
	cout << endl << endl << endl;

	return true;
}


bool IsThisMoveValid(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int whichPiece)
{
	int xCoordinate = squarePlayed % numRowsInBoard;
	int yCoordinate = squarePlayed / numRowsInBoard;
	int num = 0;
	if (whichPiece == FIRST_PIECE)
	{
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 1, 0, num) ||
			CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, -1, 0, num) ||
			CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 0, 1, num) ||
			CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 0, -1, num))
		{
			return true;
		}
	}
	else if (whichPiece == SECOND_PIECE)
	{

		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 1, 1, num) ||
			CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, -1, -1, num) ||
			CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, -1, 1, num) ||
			CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 1, -1, num))
		{
			return true;
		}
	}

	return false;
}

/*
This function checks if the player has an move or not.
if a player has no move then the opponent gets the turn
and if none of them has anything to play game ends.

WhichPiece = FirstPiece or SecondPiece
From whichPiece if this a a piece being played in the first turn or the second turn
If the piece is being played in the first piece played in a turn, call CheckLine for each of the four horizontal and vertical directions.
If none of the four calls to CheckLine then return false
If any of the four calls to CheckLine return true then return true

If the piece is being played in the second piece played in a turn then call CheckLine for each of the four
diagonal directions
If none of the four calls to CheckLine then return false
If any of the four calls to CheckLine return true then return true
AUTHOR: PARMIDA SAGHAFI

*/

bool IsAnyMoveValid(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int whichPiece)
{
	for (int i = 0; i < numRowsInBoard; i++)
		for (int j = 0; j < numRowsInBoard; j++)
		{
			if (FlipFlopBoard[i][j] == 0)
			{
				if (IsThisMoveValid(FlipFlopBoard, numRowsInBoard, player, i*numRowsInBoard + j, whichPiece))
					return true;
			}
		}

	return false;
}

bool PlacePiece(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed,
	int whichPiece, int& numberCaptured)
{

	numberCaptured = 0;
	int checkLineTable[8][3] = { 0 };
	if (IsThisMoveValid(FlipFlopBoard, numRowsInBoard, player, squarePlayed, whichPiece))
	{

		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 1, 0, numberCaptured))
		{
			checkLineTable[0][0] = numberCaptured;
			checkLineTable[0][1] = 1;
			checkLineTable[0][2] = 0;
			numberCaptured = 0;

		}
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 0, 1, numberCaptured))
		{

			checkLineTable[1][0] = numberCaptured;
			checkLineTable[1][1] = 0;
			checkLineTable[1][2] = 1;
			numberCaptured = 0;

		}
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 0, -1, numberCaptured))
		{
			checkLineTable[2][0] = numberCaptured;
			checkLineTable[2][1] = 0;
			checkLineTable[2][2] = -1;
			numberCaptured = 0;

		}
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, -1, 0, numberCaptured))
		{
			checkLineTable[3][0] = numberCaptured;
			checkLineTable[3][1] = -1;
			checkLineTable[3][2] = 0;
			numberCaptured = 0;

		}

		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 1, 1, numberCaptured))
		{
			checkLineTable[4][0] = numberCaptured;
			checkLineTable[4][1] = 1;
			checkLineTable[4][2] = 1;
			numberCaptured = 0;

		}
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, 1, -1, numberCaptured))
		{
			checkLineTable[5][0] = numberCaptured;
			checkLineTable[5][1] = 1;
			checkLineTable[5][2] = -1;
			numberCaptured = 0;

		}
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, -1, 1, numberCaptured))
		{
			checkLineTable[6][0] = numberCaptured;
			checkLineTable[6][1] = -1;
			checkLineTable[6][2] = 1;
			numberCaptured = 0;

		}
		if (CheckLine(FlipFlopBoard, numRowsInBoard, player, squarePlayed, -1, -1, numberCaptured))
		{
			checkLineTable[7][0] = numberCaptured;
			checkLineTable[7][1] = -1;
			checkLineTable[7][2] = -1;
			numberCaptured = 0;

		}
		numberCaptured = 0;
		for (int i = 0; i < 8; i++)
		{
			numberCaptured += checkLineTable[i][0];
		}
		updateBoard(FlipFlopBoard, numRowsInBoard, player, squarePlayed, checkLineTable);

		return true;
	}
	else
	{
		cout << "ERROR: illegal move" << endl;
		cout << "Try again.";
		return false;
	}
}

/*
If any of the payers places a piece and captures pieces from
the opponent then this function will be called to update the
2D array FlipFlopBoard.
AUTHOR: PARMIDA SAGHAFI

*/
bool updateBoard(int FlipFlopBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int squarePlayed, int checkLineTable[8][3])
{
	// find row and column were new piece may be placed
	int xCoordinate = squarePlayed / numRowsInBoard;
	int yCoordinate = squarePlayed % numRowsInBoard;

	for (int j = 0; j < 8; j++)
	{
		xCoordinate = squarePlayed / numRowsInBoard;
		yCoordinate = squarePlayed % numRowsInBoard;
		for (int i = 0; i <= checkLineTable[j][0]; i++)
		{
			FlipFlopBoard[xCoordinate][yCoordinate] = player;
			xCoordinate += checkLineTable[j][2];
			yCoordinate += checkLineTable[j][1];
		}
	}
	return true;
}


bool CheckLine(int FlipFlopBoard[][MAX_ARRAY_SIZE], int numRowsInBoard,
	int player, int squarePlayed,
	int xDirection, int yDirection, int& numCaptured)
{
	// This function takes the FlipFlopBoard and calculates
	// how the board changes when player player
	// (player=1 for white, player=2 for black)
	// This function checks along a row in one direction for
	// al legal move. If no legal move is found this function
	// returns false, if a legal move is found this function
	// returns true.
	// Author Janice Regan; 2021
	int otherPlayer;
	char piece = 2;           // to compare for otherPlayers
	int xIndex = 0;
	int yIndex = 0;
	int xCoordinate = 0;
	int yCoordinate = 0;
	bool edge = true;
	numCaptured = 0;

	otherPlayer = WHITEPLAYER;
	if (player == WHITEPLAYER)
	{
		otherPlayer = BLACKPLAYER;
	}

	// find row and column were new piece may be placed
	xCoordinate = squarePlayed % numRowsInBoard;
	yCoordinate = squarePlayed / numRowsInBoard;

	//if the square selected is occupied return false
	if (FlipFlopBoard[yCoordinate][xCoordinate] == player ||
		FlipFlopBoard[yCoordinate][xCoordinate] == otherPlayer)
	{
		return false;
	}


	// find the square next to the location the piece may
	// be played. Next in the direction (xDirection,yDirection)
	yIndex = yCoordinate + yDirection;
	xIndex = xCoordinate + xDirection;

	// while the square to be checked is on the board 
	// continue looking for a legal move
	// If the square is not on the board then return false
	// there is no legal move in the indicated direction
	while ((xIndex < numRowsInBoard &&
		yIndex < numRowsInBoard) &&
		(xIndex >= 0 && yIndex >= 0))
	{
		//if the location where the piece is to be placed
		//is next to an empty square or to another of the
		//player's pieces, then the there is no legal
		// move in the direction indicated 
		// return false
		if (FlipFlopBoard[yIndex][xIndex] == NOPLAYER ||
			FlipFlopBoard[yIndex][xIndex] == player)
		{
			return false;
		}
		else
		{
			// The next piece in the direction indicated is a
			// opponent's piece. The move may be legal, proceed
			// in the indicated direction and try to find a players
			// piece.  If one is found before the edge of the board
			// is reached the move is legal
			// If a legal move is found, count the number of pieces
			// captured,  then return true.
			edge = true;
			while (yIndex < numRowsInBoard &&
				xIndex < numRowsInBoard &&
				yIndex >= 0 && xIndex >= 0)
			{
				edge = false;
				if (FlipFlopBoard[yIndex][xIndex] == NOPLAYER)
				{
					//next square along the indicated direction is empty
					//move is illegal
					return false;
				}
				if (FlipFlopBoard[yIndex][xIndex] == player)
				{
					//next square along the direction indicated hold
					//one of the players pieces.  The move is legal
					break;
				}
				else
				{
					//next square along the direction indicated holds
					//an opponents piece, continue along the same 
					//direction and try the next square
					numCaptured++;
					xIndex += xDirection;
					yIndex += yDirection;
					edge = true;
				}
			}


			if (edge == true)
			{
				//The edge of the board has been reached without 
				//finding a players piece, move is not legal
				return false;
			}
			return true;
		}
	}
	//The edge of the board has been reached,
	//no legal move.  return false
	return false;
}



