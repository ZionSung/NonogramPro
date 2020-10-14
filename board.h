#ifndef BOARD_H
#define BOARD_H

#include "cdef.h"

class Board
{
    public:
        //int newPaint = 1;
        Board();
        void getLine( int*, int );
        void recover( int*, int );
        void printLine( int* );
        void printBoard();
};

#endif