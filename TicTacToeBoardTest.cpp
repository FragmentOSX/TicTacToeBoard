/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, toggleTurn)
{	
	TicTacToeBoard object;
	ASSERT_EQ(O, object.toggleTurn());
}
TEST(TicTacToeBoardTest, toggleTurnTwice)
{	
	TicTacToeBoard object;
	object.toggleTurn();
	ASSERT_EQ(X, object.toggleTurn());
}
TEST(TicTacToeBoardTest, placePiece)
{	
	TicTacToeBoard object;
	ASSERT_EQ(X, object.placePiece(0,0));
}
TEST(TicTacToeBoardTest, placePieceOccupiedSpot)
{	
	TicTacToeBoard object;
	//X places piece
	object.placePiece(0,1);
	object.toggleTurn();
	//O tries to place piece
	object.placePiece(0,1);
	ASSERT_EQ(X, object.placePiece(0,1));
}
TEST(TicTacToeBoardTest, placePieceRowOutOfBounds)
{	
	TicTacToeBoard object;
	ASSERT_EQ(Invalid, object.placePiece(5,1));
}
TEST(TicTacToeBoardTest, placePieceColOutOfBounds)
{	
	TicTacToeBoard object;
	ASSERT_EQ(Invalid, object.placePiece(1,5));
}
TEST(TicTacToeBoardTest, placePieceBothOutOfBounds)
{	
	TicTacToeBoard object;
	ASSERT_EQ(Invalid, object.placePiece(5,6));
}
TEST(TicTacToeBoardTest, getPieceAtSpot)
{	
	TicTacToeBoard object;
	//X places piece
	object.placePiece(0,1);
	ASSERT_EQ(X, object.getPiece(0,1));
}
TEST(TicTacToeBoardTest, getPieceUnoccupiedSpot)
{	
	TicTacToeBoard object;
	ASSERT_EQ(Blank, object.getPiece(0,1));
}
TEST(TicTacToeBoardTest, getPieceOutOfBounds)
{	
	TicTacToeBoard object;
	ASSERT_EQ(Invalid, object.getPiece(0,5));
}
TEST(TicTacToeBoardTest, placePieceAfterWin)
{	
	TicTacToeBoard object;
	//X
	object.placePiece(0,1);
	//O
	object.placePiece(1,1);
	//X
	object.placePiece(0,0);
	//O
	object.placePiece(1,2);
	//X
	object.placePiece(0,2);
	//trying to place O, should remain X
	ASSERT_EQ(X, object.placePiece(0,2));
}
TEST(TicTacToeBoardTest, getWinnerNotOver)
{	
	TicTacToeBoard object;
	object.placePiece(1,1);
	ASSERT_EQ(Invalid, object.getWinner());
}
TEST(TicTacToeBoardTest, getWinnerNoWinner)
{	
	TicTacToeBoard object;
	
	/*Board format:
	
      0 1 2
	0 X O X
	1 O O X
	2 X X O
	
	*/
	
	//X
	object.placePiece(0,0);
	//O
	object.placePiece(0,1);
	//X
	object.placePiece(0,2);
	//O
	object.placePiece(1,0);
	//X
	object.placePiece(1,2);
	//O
	object.placePiece(1,1);
	//X
	object.placePiece(2,0);
	//O
	object.placePiece(2,2);
	//X
	object.placePiece(2,1);

	ASSERT_EQ(Blank, object.getWinner());
}
TEST(TicTacToeBoardTest, getWinnerBoardNotFull)
{	
	TicTacToeBoard object;
	//X
	object.placePiece(0,1);
	//O
	object.placePiece(1,1);
	//X
	object.placePiece(0,0);
	//O
	object.placePiece(1,2);
	//X
	object.placePiece(0,2);
	ASSERT_EQ(X, object.getWinner());
}
TEST(TicTacToeBoardTest, placePieceAfterWinEmptySpot)
{	
	TicTacToeBoard object;
	//X
	object.placePiece(0,1);
	//O
	object.placePiece(1,1);
	//X
	object.placePiece(0,0);
	//O
	object.placePiece(1,2);
	//X
	object.placePiece(0,2);
	//trying to place O, should be blank
	ASSERT_EQ(Blank, object.placePiece(2,2));
}
TEST(TicTacToeBoardTest, getWinnerOWins)
{	
	TicTacToeBoard object;
	
	//X
	object.placePiece(1,1);
	//O
	object.placePiece(2,0);
	//X
	object.placePiece(1,2);
	//O
	object.placePiece(2,1);
	//X
	object.placePiece(0,1);
	//O
	object.placePiece(2,2);
	ASSERT_EQ(O, object.getWinner());
}