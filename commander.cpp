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
    int round = 1;
    while( new_pixel > 0 ){
        printf("################################################\n                   ROUND*%d*\n################################################\n\n", round);
        oldBoard = newBoard;
        newBoard = lgSolver.Sub2( data, newBoard );
        newBoard = lgSolver.Sub1( data, newBoard );
        new_pixel = useBoard.CompareBoard( oldBoard, newBoard );
        useBoard.printBoard(newBoard);
        round++;
    }
    printf("TOTAL ROUND = %d\n", round-1 );
    printf("################################################\n                TOTAL NEW PAINT\n################################################\n");
    useBoard.CompareBoard( b, newBoard );        
    useBoard.printBoard(newBoard);
    return CORRECT;

}