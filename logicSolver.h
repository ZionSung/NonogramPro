#ifndef LOGICSOLVER_H
#define LOGICSOLVER_H

#include <cstdio>
#include <cstring>
#include "board.h"

class LogicSolver
{
    public:
        LogicSolver() {}
        Board RLmost( int* , Board );
        Board Sub2( int*, Board );
        
        int EdgeSpreading( int*, Board );
        int Padding( int*, Board );
        int AccRLmost( int*, Board ); // According
        void ScanLine( int* );
};

#endif 