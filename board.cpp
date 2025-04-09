#include "board.h"

const int BOARD_SIZE = 8;
const std::unordered_map<int,char> Board::pieces = {{0,L'.'},
                                            {1,L'♙'},
                                            {2,L'♘'},
                                            {3,L'♗'},
                                            {5,L'♖'},
                                            {9,L'♕'},
                                            {10,L'♔'},
                                            {-1,L'♟'},
                                            {-2,L'♞'},
                                            {-3,L'♝'},
                                            {-5,L'♜'},
                                            {-9,L'♛'},
                                            {-10,L'♚'}};

Board::Board(): size{BOARD_SIZE}
{
    // White down, Black up

    board = {{-5,-2,-3,-9,-10,-3,-2,-5},
            {-1,-1,-1,-1,-1,-1,-1,-1},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1},
            {5,2,3,9,10,3,2,5}};
}

Board::Board(const Board &boardToCopy): size{boardToCopy.getSize()}
{
    for(int i = 0; i < boardToCopy.getSize(); i++)
    {
        for(int j = 0; j < boardToCopy.getSize(); j++)
        {
            board[i][j] = boardToCopy.board[i][j];
        }
    }
}

Board::~Board()
{

}

int Board::getSize() const
{
    return size;
}

void Board::setCell(int row, int col, int value)
{
    if (row >= 0 && row < size && col >= 0 && col < size)
    {
        board[row][col] = value;
    }
    else
    {
        throw std::out_of_range("Invalid row or column index");
    }
}

int Board::getCell(int row, int col) const
{
    return Board::board[row][col];
}

char Board::getPiece(int row, int col) const
{
    return Board::pieces.at(getCell(row,col));
}

std::wostream &operator<<(std::wostream &out, const Board &board)
{
    for (int i = 0; i < board.getSize(); i++)
    {
        for(int j = 0; j < board.getSize(); j++)
        {
            out << board.getPiece(i,j) << L"  ";
        }
        out << std::endl;
    }

    return out;
}