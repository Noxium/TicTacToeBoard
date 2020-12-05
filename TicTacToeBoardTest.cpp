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
    out = tttb.placePiece(0, 0); // X
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, Place2Piece)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    out = tttb.placePiece(0, 1); // O
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, Place3Piece) {
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    out = tttb.placePiece(0, 2); // X
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, InvalidPlacePiece1)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.placePiece(-1, 2); // O
	ASSERT_TRUE(out == Invalid);
}

TEST(TicTacToeBoardTest, InvalidPlacePiece2)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.placePiece(1, 4); // O
	ASSERT_TRUE(out == Invalid);
}

TEST(TicTacToeBoardTest, NoWinnerDuringGame)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == Invalid);
}

TEST(TicTacToeBoardTest, GetPieceInvalidLocation)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getPiece(-3, 1); // O
	ASSERT_TRUE(out == Invalid);
}

TEST(TicTacToeBoardTest, GetPieceFunctionality)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getPiece(0, 1); // O
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, PlacePieceOnPiece)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    out = tttb.placePiece(0, 1); // X
	ASSERT_TRUE(out == O);
}

TEST(TicTacToeBoardTest, TieGame)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 1); // X
    tttb.placePiece(0, 0); // O
    tttb.placePiece(1, 0); // X
    tttb.placePiece(0, 2); // O
    tttb.placePiece(1, 1); // X
    tttb.placePiece(1, 2); // O
    tttb.placePiece(2, 0); // X
    tttb.placePiece(2, 1); // O
    tttb.placePiece(2, 2); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == Blank);
}

TEST(TicTacToeBoardTest, WinOnLastMove)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 1); // X
    tttb.placePiece(0, 2); // O
    tttb.placePiece(1, 2); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(2, 0); // X
    tttb.placePiece(2, 1); // O
    tttb.placePiece(2, 2); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == X);
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
    tttb.placePiece(0, 0); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(0, 1); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getWinner();
	ASSERT_TRUE(out == X);
}

TEST(TicTacToeBoardTest, OWinHoriz)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(2, 1); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 2); // X
    tttb.placePiece(1, 2); // O
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


TEST(TicTacToeBoardTest, XWinHoriz_False)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(0, 1); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getWinner();
	ASSERT_FALSE(out == O);
}

TEST(TicTacToeBoardTest, OWinHoriz_False)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(2, 1); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 2); // X
    tttb.placePiece(1, 2); // O
    out = tttb.getWinner();
	ASSERT_FALSE(out == X);
}

TEST(TicTacToeBoardTest, XWinVert_False)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 0); // X
    tttb.placePiece(1, 1); // O
    tttb.placePiece(2, 0); // X
    out = tttb.getWinner();
	ASSERT_FALSE(out == O);
}

TEST(TicTacToeBoardTest, OWinVert_False)
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
	ASSERT_FALSE(out == X);
}

TEST(TicTacToeBoardTest, XWinDiagNeg_False)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(0, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 1); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(2, 2); // X
    out = tttb.getWinner();
	ASSERT_FALSE(out == O);
}

TEST(TicTacToeBoardTest, OWinDiagNeg_False)
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
	ASSERT_FALSE(out == X);
}

TEST(TicTacToeBoardTest, XWinDiagPos_False)
{
	TicTacToeBoard tttb;
    Piece out;
    tttb.placePiece(2, 0); // X
    tttb.placePiece(0, 1); // O
    tttb.placePiece(1, 1); // X
    tttb.placePiece(1, 0); // O
    tttb.placePiece(0, 2); // X
    out = tttb.getWinner();
	ASSERT_FALSE(out == O);
}

TEST(TicTacToeBoardTest, OWinDiagPos_False)
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
	ASSERT_FALSE(out == X);
}

