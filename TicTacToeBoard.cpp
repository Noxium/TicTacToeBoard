#include "TicTacToeBoard.h"
#include <iostream>
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  turn = (turn == X) ? O : X;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > BOARDSIZE-1 || column > BOARDSIZE-1 || row < 0 || column < 0) {
    return Invalid;
  }
  Piece temp = getPiece(row, column);
  if(temp != Blank) {
    return temp;
  }
  temp = turn;
  board[row][column] = turn;
  Piece tempWinner = getWinner();
  if(tempWinner != Invalid) {
    return tempWinner;
  }
  toggleTurn();
  return temp;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > BOARDSIZE-1 || column > BOARDSIZE-1 || row < 0 || column < 0) {
    return Invalid;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int total_pieces_on_board = 0;
  int num_X_horiz = 0;
  int num_O_horiz = 0;
  int num_X_vert = 0;
  int num_O_vert = 0;
  int num_X_diag_neg = 0;
  int num_O_diag_neg = 0;
  int num_X_diag_pos = 0;
  int num_O_diag_pos = 0;
  for(int i = 0; i < BOARDSIZE; i++) {
    num_X_horiz = num_O_horiz = num_X_vert = num_O_vert = 0;
    for(int j = 0; j < BOARDSIZE; j++) {
      if(getPiece(i, j) != Blank) {
        total_pieces_on_board++;
      }
      if(getPiece(i, j) == X) {
        num_X_horiz++;
      }
      if(getPiece(i, j) == O) {
        num_O_horiz++;
      }
      if(getPiece(j, i) == X) {
        num_X_vert++;
      }
      if(getPiece(j, i) == O) {
        num_O_vert++;
      }
    }
    if(num_X_horiz == BOARDSIZE || num_X_vert == BOARDSIZE) {
      return X;
    }
    if(num_O_horiz == BOARDSIZE || num_O_vert == BOARDSIZE) {
      return O;
    }
    if(getPiece(i, i) == X) {
      num_X_diag_neg++;
    }
    if(getPiece(i, i) == O) {
      num_O_diag_neg++;
    }
    if(getPiece(BOARDSIZE - 1 - i, i) == X) {
      num_X_diag_pos++;
    }
    if(getPiece(BOARDSIZE - 1 - i, i) == O) {
      num_O_diag_pos++;
    }
  }
  if(num_X_diag_neg == BOARDSIZE || num_X_diag_pos == BOARDSIZE) {
    return X;
  }
  if(num_O_diag_neg == BOARDSIZE || num_O_diag_pos == BOARDSIZE) {
    return O;
  }

  if(total_pieces_on_board == BOARDSIZE * 3) {
    return Blank;
  }
  return Invalid;
}
