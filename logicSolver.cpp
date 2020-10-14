#include "logicSolver.h"

int onePosition[maxClue]{};
int oneNum[maxClue]{};
int zeroNum[maxClue]{};
int emptyNum[maxClue]{};
int oneSeg = 0;
int zeroSeg = 0;
int emptySeg = 0;
int oneCont = 0;
int zeroCont = 0;
int emptyCont = 0;
int onePositionCount = 0;
int postionCount = 0;

int shift = 0;

int finish[probLen]{};

int LogicSolver::RLmost( int *data, Board b ){

    // run each line
    for( int num = 0; num < probLen; num++ ){
        //printf("%d -- \n", num+1 );
        // get line
        int line[Len];
        b.getLine(line, num);
        //printf("1: ");
        //b.printLine(line);
        // main
        int dataShift = num*maxClue;
        int j = data[dataShift];
        int totaClue = 0;
        for( int i = 0; i < j; i++ ){
            totaClue += data[dataShift+i+1]; // because the fisrt one is j
        }
        totaClue = totaClue + j - 1;
        shift = Len - totaClue;
        int point = shift;
        //printf("shift = %d\n", shift );
        for( int i = 0; i < j; i++ ){

            if( shift < data[dataShift+i+1] ){
                int paint = data[dataShift+i+1] - shift; // how many spaces we shall paint
                for( int p = 0; p < paint; p++ ){
                    line[p + point] = 1;
                }
            }
            
            point += data[dataShift+i+1];
            point++;
        }
        //printf("2: ");
        //b.printLine(line);
        //ScanLine(line);
        // recover to board
        b.recover(line,num);
    }
    
    b.printBoard();

    return CORRECT;
}

int LogicSolver::EdgeSpreading( int *data, Board b ){

    //printf("EdgeSpreading\n\n");

    for( int num = 0; num < probLen; num++ ){
        int line[Len];
        b.getLine(line, num);
        b.printLine(line);

    
        // the first
        if( line[0] == 1 ){
            //printf("the first!\n");
            int edgeClue = data[num*maxClue + 1];
            printf("num = %d\n", num*maxClue+1 );
            printf("edgeClue = %d\n", edgeClue );
            for( int i = 1; i < edgeClue; i++ ){
                line[i] = 1;
            }
            line[edgeClue] = 0;
        }
    
        // the last
        if( line[Len-1] == 1 ){
            //printf("the last!\n");
            int edgeClue = data[data[num*maxClue] + num*maxClue ] - 1;
            printf("edgeClue = %d\n", edgeClue );
            line[Len - edgeClue - 2] = 0;
            //b.printLine(line);
            while( edgeClue > 0 ){
                int i = Len-2;
                printf("i = %d\n", i );
                line[i] = 1;
                i--;
                edgeClue--;
            }
        }

        //b.printLine(line);
        b.recover(line,num);
    }

    b.printBoard();
    //printf("SUB1 ========== SUB1 ========== SUB1 ==========\n\n");

    return CORRECT;   
}

int LogicSolver::Padding( int *data, Board b ){

    //printf("Padding\n\n");

    for( int num = 9; num < 10; num++ ){

        int line[Len];
        b.getLine(line, num);
        

        if( finish[num] == 0 ){ // is finish?

            printf("new start =>> line %d\n", num );
            b.printLine(line);
            printf("\n");

            int first_point;
            int temp_point = 0;
            int point = 0;
            int j = data[num*maxClue];
            int j_point = 1;
            int INCORRECT = 0;
            int toBeConfirm = 0;

            
            //int tailFringePadding = 0;
            int foreheadFringePadding = 0; 

            /* ==================================================
                maybe this section can improve 
               ==================================================
            
            
            // we can put a door here
            //foreheadFringePadding
            int first_clue = data[ num*maxClue + j_point ];
            printf("first clue = %d\n", first_clue );
            int flag_P0 = 30; // avoid flag_P0 == 0
            for( int i = 0; i < first_clue; i++ ){
                printf("Hi~\n");
                if( line[i] == 1 ){
                    break;
                }
                else if( line[i] == 0 ){
                    flag_P0 = i;
                }
            }
            printf("flagP0 = %d\n", flag_P0 );
            

            if( flag_P0 != 30 && line[flag_P0+1] != 0 ){
                flag_P0++;
                for( int i = 0; i < flag_P0; i++ ){
                    line[i] = 0;
                }
                if( line[flag_P0] == 1 ){ // edge padding "1"
                    first_clue--;
                    flag_P0++;
                    while( first_clue > 0 ){
                        line[flag_P0] = 1;
                        flag_P0++;
                    }
                    line[flag_P0] = 0;
                }
                j_point++;
                flag_P0++;
                point = flag_P0;
            }

            
                ====================================================
            */
            


            while( j_point <= j && point < Len ){
                
                /*
                if( point == Len ){
                    //printf("out of boundary\n");
                    break;
                }
                */
                
                

                //printf("check point = %d\n", point );
                printf("line[%d] = %d\n", point, line[point] );
                if( line[point] == 2 ){
                    foreheadFringePadding = 1;
                    printf("line[point] == X\n");
                    //printf("point = %d\n", point );
                    point++;
                }
                else if( line[point] == 0 ){
                    
                    printf("line[point] == 0\n");
                    printf("foreheadFringePadding = %d\n", foreheadFringePadding );
                    printf("line[point] = %d, point = %d\n", line[point+1], point+1 );
                    // first
                    if( foreheadFringePadding != 1 && line[point+1] == 1 ){ // line[point+1] == 1
                        printf("hello 0\n");
                        point+=2; // refresh to next point
                        //printf("point = %d\n", point );
                        if( point == Len ){
                            //printf("over boundary\n");
                            finish[num] = 1;
                            break;
                        }
                        /*
                        else if( line[point] == 0 ){
                            printf("CONFLICT!! -- in fringe padding\n");
                            return CONFLICT;
                        }
                        */

                        int clue = data[ num*maxClue + j_point ] - 1;
                        while( clue > 0 ){
                            line[point] = 1;
                            point++;
                            clue--;
                        }
                        line[point] = 0;
                        j_point++;
                        
                        if( j_point == j+1 ){
                            // paint remaining "0"
                            for( int i = 0; i < Len; i++ ){
                                if( line[i] == 2 ){
                                    line[i] = 0;
                                }
                            }

                            // finish this line
                            finish[num] = 1;
                        } 
                        
                    }
                    else if( foreheadFringePadding != 1 && line[point+1] == 2 ){
                        
                        int clue = data[ num*maxClue + j_point ];
                        point++;

                        // Here we can put RLmost( cutting )
                        if( clue == Len - point ){ // if fit
                            while( clue > 0 ){
                                line[point] = 1;
                                point++;
                                clue--;
                            }
                            j_point++;
                            if( j_point == j+1 ){
                                finish[num] = 1;
                                break; // need or not?
                            }
                        }

                    }
                    else{
                        point++;
                    }
                }
                else if( line[point] == 1 ){ // enter into one clue and check it

                    printf("line[point] == 1\n");
                    //printf("point = %d\n", point );
                    //printf("check enter ==== ");
                    //b.printLine(line);
                    first_point = point - 1;

                    int clue = data[ num*maxClue + j_point ] - 1;
                    int temp_clue = clue;
                    //printf(" data[ num*maxClue + j_point ] = %d\n", data[ num*maxClue + j_point ]);
                    //printf("j = %d, j_point = %d\n",j, j_point );
                    //printf("clue = %d\n", clue );
                    
                    point++;
                    
                    //printf("!! point = %d\n", point );
                    //printf("check ------- line[%d] = %d\n", point, line[point] );

                    while( clue > 0 ){

                        //printf("line[%d] = %d\n", point, line[point] );
                        if( line[point] == 0 ){
                            //printf("1 INCORRECT! ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n");

                            temp_point = point+1;

                            INCORRECT = 1;
                            break;
                        }
                        else if( line[point] == 2 ){
                            //printf("to be confirm\n");
                            toBeConfirm = 1;
                            point++;
                            clue--;
                        }
                        else{
                            //printf("1 Yes!\n");
                            point++;
                            clue--;
                        }
                    }

                    

                    if( INCORRECT == 1 ){

                        printf("INCORRECT == 1\n");
                        point -= 2;
                        while( temp_clue > 0 ){ //  point > point - temp_clue, point--
                            line[point] = 1;
                            point--;
                            temp_clue--; 
                        }
                        point = temp_point;
                        j_point++;

                        if( j_point == j+1 ){
                            // paint remaining "0"
                            for( int i = 0; i < Len; i++ ){
                                if( line[i] == 2 ){
                                    line[i] = 0;
                                }
                            }

                            // finish this line
                            finish[num] = 1;
                        } 
                    }
                    else if( toBeConfirm == 1 ) { // this clue is finish, so we can paint "0" to the both sides of "1"
                        printf("Enter into toBeConfirm\n");
                        //printf("check --------------- line[%d] = %d\n", first_point, line[first_point] );
                        
                        // padding 1
                        if( toBeConfirm == 1 && (line[point] == 0 || point == Len) ){ // || point == (Len - 1)
                            if( line[first_point] == 0 || first_point < 0 ){
                                //printf("first_point = %d\n", first_point );
                                int FirstOnePoint = first_point + 2;
                                for( int i = FirstOnePoint; i < point; i++ ){
                                    line[i] = 1;
                                }
                            }
                        }
                        j_point++;
                    }
                    else{ // have already paint "1", and it also finish, so we can paint remaining "0"
                        printf("Enter into ELSE\n");
                        line[first_point] = 0;


                        // padding 0
                        if( point < Len ){ //  over boundary
                            line[point] = 0;
                        }
                        //printf("check!!!!!!!!!!!!!!!!!!!!! ");
                        //b.printLine(line);
                        j_point++;
                        printf("j_point = %d, j = %d\n", j_point, j );
                        if( j_point == j+1 ){
                            // paint remaining "0"
                            for( int i = 0; i < Len; i++ ){
                                if( line[i] == 2 ){
                                    line[i] = 0;
                                }
                            }

                            // finish this line
                            finish[num] = 1;
                        } 

                    }
                    foreheadFringePadding = 0;
                    printf("Solution\n");
                    b.printLine(line);
                }
            } // end while

            //printf("out!\n");       
        } //  end if
        b.recover(line,num);
        b.printLine(line);
    } // end for
    //printf("printf BORD!!\n");
    b.printBoard();
    
    printf("finish\n");
    for( int i = 0; i < probLen; i++ ){
        if( finish[i] == 1 ){
            printf("finish[%d] == 1\n", i );
        }
    }
    
    return CORRECT;
}


int LogicSolver::AccRLmost( int *data, Board b ){

    /*
    printf("%d\n", data[0]);
    printf("%d\n", data[1]);
    printf("%d\n", data[2]);
    printf("%d\n", data[3]);
    printf("%d\n", data[4]);
    */

    //int num = 0;
    //int i = Len;
    //int j = data[num*maxClue];

    int line[Len];
    b.getLine(line, 1);

    ScanLine(line);

    
    


    /*
    // run each line
    for( int num = 0; num < probLen; num++ ){
            printf("%d -- \n", num+1 );
            // get line
            int line[Len];
            b.getLine(line, num);
            printf("1: ");
            b.printLine(line);
            // main
            // find the Rmost One
            

            printf("2: ");
            b.printLine(line);
            //ScanLine(line);
            // recover to board
            b.recover(line,num);
        }
    
    b.printBoard();
    */
    printf("\n\nSUB2 ========== SUB2 ========== SUB2 ==========\n\n");

    return CORRECT;    
}


void LogicSolver::ScanLine( int *line ){

    memset(onePosition,0,maxClue<<2);
    memset(oneNum,0,maxClue<<2);
    memset(zeroNum,0,maxClue<<2);
    memset(emptyNum,0,maxClue<<2);
    oneSeg = 0;
    zeroSeg = 0;
    emptySeg = 0;
    oneCont = 0;
    zeroCont = 0;
    emptyCont = 0;
    onePositionCount = 0;
    postionCount = 0;

    for( int i = 0; i < Len; i++ ){
        //printf("A\n");
        if( line[i] == 1 ){
            if( oneCont == 0 ){
                oneSeg++;
                onePosition[onePositionCount] = postionCount;
            }
            
            oneNum[oneSeg]++;
            oneCont = 1;
            zeroCont = 0;
            emptyCont = 0;
            //printf("positionCount = %d\n", postionCount );
            onePositionCount++;
            //printf("One %d\n", oneNum[oneSeg]);
        }
        else if( line[i] == 0 ){
            if( zeroCont == 0 ){
                zeroSeg++;
            }
            zeroNum[zeroSeg]++;
            zeroCont = 1;
            oneCont = 0;
            emptyCont = 0;
            
            //printf("Zero %d\n", zeroNum[zeroSeg]);
        }
        else{
            if( emptyCont == 0 ){
                emptySeg++;
            }
            emptyNum[emptySeg]++;
            emptyCont = 1;
            zeroCont = 0;
            oneCont = 0;
            
            //printf("EmptySeg = %d\n", emptySeg );
            //printf("Empty %d\n", emptyNum[emptySeg]);
        } 
        postionCount++;
    }

    oneNum[0] = oneSeg;
    zeroNum[0] = zeroSeg;
    emptyNum[0] = emptySeg;

    printf("\nOne -> ");
    for( int i = 0; i < maxClue; i++ ){
        printf("%d ", oneNum[i] );
    }
    printf("\nZero -> ");
    for( int i = 0; i < maxClue; i++ ){
        printf("%d ", zeroNum[i] );
    }
    printf("\nEmpty -> ");
    for( int i = 0; i < maxClue; i++ ){
        printf("%d ", emptyNum[i] );
    }
    printf("\nOnePosition ->" );
    for( int i = 0; i < maxClue; i++ ){
        printf("%d ", onePosition[i] );
    }

    printf("\n\n");

}

