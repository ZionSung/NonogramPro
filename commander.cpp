#include "commander.h"

int Commander::Start( int* data ){

    // initialize board
    Board b;
    Board useBoard;
    
    // Logic Solve
    LogicSolver lgSolver;
    FixPaint fpSolver;
    Board newBoard;
    Board oldBoard;

    int new_pixel = 1;
    //b.printBoard();
    //b1 = fpSolver.lineSolving( data, b );
    //useBoard.CompareBoard( b, b1 );
    
    newBoard = lgSolver.RLmost( data, newBoard );
    int round = 0;
    while( new_pixel > 0 ){
        oldBoard = newBoard;
        newBoard = lgSolver.Sub2( data, newBoard );
        newBoard = lgSolver.Sub1( data, newBoard );
        new_pixel = useBoard.CompareBoard( newBoard, oldBoard );
        //if( round == 2 )break;
        round++;
    }
    printf("round = %d\n", round );
    useBoard.CompareBoard( b, newBoard );        

    return CORRECT;

}