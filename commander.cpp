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
    //b1 = fpSolver.lineSolving( data, b );
    //useBoard.CompareBoard( b, b1 );
    b2 = lgSolver.RLmost( data, b );
    printf("############## SUB2 ################\n");
    b2 = lgSolver.Sub2( data, b2 );
    printf("\n#########################\n          NEXT         \n#########################\n\n\n");
    b2 = lgSolver.Sub1( data, b2 );
    //printf("############## NEXT SUB2 #################\n");
    //b2 = lgSolver.Sub2( data, b2 );
    //useBoard.CompareBoard( b2, b1 );
    
    
    //lgSolver.EdgeSpreading( data, b1 );
    //lgSolver.Padding( data, b );
    //lgSolver.Padding( data, b );
    //lgSolver.Padding( data, b );
    //lgSolver.AccRLmost( data, b );

    return CORRECT;

}