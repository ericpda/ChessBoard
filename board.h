#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>
#include <unordered_map>

class Board{
    private:
        std::vector<std::vector<int>> board;
        int size;
        static const std::unordered_map<int,char> pieces;
    public:
        Board();
        Board(const Board &boardToCopy);
        ~Board();
        int getSize() const;
        void setCell(int row, int col, int value);
        int getCell(int row, int col) const;
        char getPiece(int row, int col) const;
        friend std::wostream &operator<<(std::wostream &out, const Board &board);
};

#endif