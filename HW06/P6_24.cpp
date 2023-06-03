//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-6-3
//  FILENAME   : P6_24.CPP
//  DESCRIPTION   : This is a program of knight tour
//============================

#include <iostream>
#include <iomanip>
#include <random>
#define SIZE 8

using namespace std;

int validMove(int, int ,int[][SIZE]);
void clearBoard(int[][SIZE]);
void printBoard(int[][SIZE]);
void fillAccess(int[][SIZE]);
int getMaxAccess(int[][SIZE]);

int horizontal[SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 }, vertical[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
    int  access[SIZE][SIZE] ;
    int board[SIZE][SIZE] ;
    
    int currentRow, currentCol, moveNum = 0, accessNum, done = 0, minRow, minCol, minAccess;

    srand(time(NULL));
    
    clearBoard(board);
    fillAccess(access);
    minAccess = getMaxAccess( access ) + 1;
    
    currentRow = rand() % SIZE;
    currentCol = rand() % SIZE;
    board[ currentRow ][currentCol] = ++ moveNum;
    
    
    
    // start to move 64 steps
    
    while( !done ){
        
        accessNum = minAccess;

        int tryRow, tryCol;

        for(int moveType = 0; moveType <= 7; moveType ++){
            
            tryRow = currentRow + vertical[ moveType ];
            tryCol = currentCol + horizontal[ moveType ];
            
            if( validMove(tryRow, tryCol, board)){
                if( access[tryRow][tryCol] < accessNum){
                    accessNum = access[tryRow][tryCol];
                    minRow    = tryRow;
                    minCol    = tryCol;
                }
                access[ tryRow ][ tryCol ]--; // 8 place minus 1
            }
        }
        
        
        
        // no move anymore
        if(accessNum == minAccess){
            done = 1;
        }
        else{
            currentRow  = minRow;
            currentCol  = minCol;
            board[ currentRow ][currentCol] = ++ moveNum;
        }
        
    }
    
    cout <<"The tour ended with "<< moveNum<< " moves." << endl;
    cout << "This is" << ((moveNum==64)?" ":" not ")<<"a full tour!\n";
    cout << "--- The board for this test is: ---" <<std::endl;
    
    printBoard(board);

    return 0;
    
}

int validMove(int row, int column, int board[][SIZE]){
    
    return (row >= 0 && row <= (SIZE - 1)) && (column >=0 && column <= (SIZE - 1)) && (board[row][column] == 0);
    
}

void clearBoard(int board[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = 0;
        }
    }
}

void printBoard(int a[][SIZE]){
    int i, j;
    for(i = 0; i < SIZE ; i++){
        for(j = 0; j < SIZE; j++){
            cout << std::setw(3) << std::right<<a[i][j];
        }
        cout <<std::endl;
    }
    cout <<"---------------------------\n";
}

void fillAccess(int board[][SIZE]){
    clearBoard(board);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0;j < SIZE;j++){
            for(int moveType = 0; moveType <=7; moveType ++){
                int tryRow = i + vertical[ moveType ];;
                int tryCol = j + horizontal[ moveType ];
                if(tryRow >=0 && tryRow < SIZE && tryCol >=0 && tryCol < SIZE){
                    board[tryRow][tryCol] ++;
                }
            }
        }
    }
}

int getMaxAccess( int board[][SIZE] ){
    int max = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(max < board[i][j]){
                max = board[i][j];
            }
        }
    }
    return max;
}
