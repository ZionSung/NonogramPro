#include "commander.h"

int Commander::Start( int* data ){

    // initialize board
    Board b;
    
    // Logic Solve
    LogicSolver lgSolver;
    FixPaint fpSolver;
    Board b1;
    //b.printBoard();
    fpSolver.lineSolving( data, b );
    //fpSolver.lineSolving( data, b );
    //printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
    //lgSolver.RLmost( data, b1 );
    //lgSolver.EdgeSpreading( data, b1 );
    //lgSolver.Padding( data, b );
    //lgSolver.Padding( data, b );
    //lgSolver.Padding( data, b );
    //lgSolver.AccRLmost( data, b );

    return CORRECT;

}