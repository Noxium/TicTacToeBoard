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

TEST(TicTacToeBoardTest, Place1Piece)
{
	TicTacToeBoard tttb;
    Piece out;
    out = tttb.placePiece(0, 0);
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, Place2Piece)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0);
    out = tttb.placePiece(0, 1);
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, Place3Piece)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0);
    tttb.placePiece(0, 1);
    out = tttb.placePiece(0, 2);
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, NoWinnerDuringGame)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0);
    tttb.placePiece(0, 1);
    tttb.placePiece(0, 2);
    out = tttb.getWinner();
	ASSERT_TRUE(out == Invalid);
}

TEST(TicTacToeBoardTest, InitializeBlank)
{
	TicTacToeBoard tttb;
    bool isBlank = true;
    for(int i = 0; i < BOARDSIZE; i++) {
      for(int j = 0; j < BOARDSIZE; j++) {
        if(tttb.getPiece(i, j) != Blank) {
          isBlank = false;
          break;
        }
      }
    }
	ASSERT_TRUE(isBlank);
}

TEST(TicTacToeBoardTest, XWinHoriz)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0);
    tttb.placePiece(1, 0);
    tttb.placePiece(0, 1);
    tttb.placePiece(1, 1);
    tttb.placePiece(0, 2);
    tttb.placePiece(0, 2);
    out = tttb.getWinner();
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, OWinHoriz)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0);
    tttb.placePiece(1, 0);
    tttb.placePiece(2, 1);
    tttb.placePiece(1, 1);
    tttb.placePiece(2, 2);
    tttb.placePiece(1, 2);
    out = tttb.getWinner();
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, XWinVert)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 0); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 0); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, OWinVert)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 2); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 0); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 0); // X
    tttb.placePiece(2, 1); // O
    out = tttb.getWinner();
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, XWinDiagNeg)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 1); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(2, 2); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, OWinDiagNeg)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 1); // X
    tttb.placePiece(0, 0); // O
    tttb.placePiece(1, 2); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 1); // X
    tttb.placePiece(2, 2); // O
    out = tttb.getWinner();
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, XWinDiagPos)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(2, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 1); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, OWinDiagPos)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 1); // X
    tttb.placePiece(2, 0); // O
    tttb.placePiece(1, 2); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 1); // X
    tttb.placePiece(0, 2); // O
    out = tttb.getWinner();
	ASSERT_TRUE(out == O);
}

