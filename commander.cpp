#include "commander.h"

int Commander::Start( int* data ){

    // initialize board
    Board b;
    Board useBoard;
    
    // Logic Solve
    LogicSolver lgSolver;
    FixPaint fpSolver;
    Board b1;
    Board b2;

    //b.printBoard();
    b1 = fpSolver.lineSolving( data, b );
    useBoard.CompareBoard( b, b1 );
    b2 = lgSolver.RLmost( data, b );
    useBoard.CompareBoard( b, b2 );
    useBoard.CompareBoard( b1, b2 );
    //lgSolver.EdgeSpreading( data, b1 );
    //lgSolver.Padding( data, b );
    //lgSolver.Padding( data, b );
    //lgSolver.Padding( data, b );
    //lgSolver.AccRLmost( data, b );

    return CORRECT;

}