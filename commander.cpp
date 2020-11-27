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
        round++;
    }
    printf("round = %d\n", round );
    useBoard.CompareBoard( newBoard, b );


    /*
    printf("############## SUB2 ################\n");
    newBoard = lgSolver.Sub2( data, newBoard );
    printf("\n#########################\n          NEXT         \n#########################\n\n\n");
    b2 = lgSolver.Sub1( data, newBoard );
    new_pixel = useBoard.CompareBoard( b2, b );
    printf("\n#########################\n          NEXT         \n#########################\n\n\n");
    b2 = lgSolver.Sub2( data, b2 );
    useBoard.CompareBoard( b2, b );
    printf("\n#########################\n          NEXT         \n#########################\n\n\n");
    b2 = lgSolver.Sub1( data, b2 );
    useBoard.CompareBoard( b2, b );
    printf("\n#########################\n          NEXT         \n#########################\n\n\n");
    b2 = lgSolver.Sub2( data, b2 );
    useBoard.CompareBoard( b2, b );
    */
        

    return CORRECT;

}