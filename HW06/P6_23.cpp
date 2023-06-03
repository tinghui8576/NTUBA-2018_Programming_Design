//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-31
//  FILENAME   : P6_23.CPP
//  DESCRIPTION   : This is a program of turtle graphics
//============================

#include <iostream>
#include <iomanip>
using namespace std;

void draw( int, int*, int*, bool[][20]);
void print( bool[][20]);
int main(){
    bool pen = false;
    bool floor[20][20] = {false};
    int command = 0;
    int direction = 0;
    int tur_c = 0, tur_r = 0;
    cout << "Give some commands to start to let the turtle draw" << endl;
    cout << "Commands:" << endl;
    cout << setw(4) << "1" << setw(10) << "
    while(cin >> command && command != 9){
        switch(command){
           case 1:
                pen = true;
                break;
            case 2:
                pen = false;
                break;
            case 3:
                if(pen == true)
                    direction++;
                else
                    cout << "Sorry, the pen is not up! You can't change direction now." << endl;
                break;
            case 4:
                if(pen == true)
                    direction--;
                else
                    cout << "Sorry, the pen is not up! You can't change direction now." << endl;
                break;
            case 5:
                if(pen == true)
                    draw( direction, &tur_c, &tur_r, floor);
                else
                    cout << "Sorry, the pen is not up! You can't draw now." << endl;
                break;
            case 6:
                print( floor);
                break;
        }
    }
    return 0;
}
void draw(int dir, int *tur_c, int *tur_r, bool floor[][20]){
    int step = 0;
    cin >> step;
    switch(dir % 4){
        case 0:
            for(int i = 1; i <= step; i++)
                floor[*tur_r][*tur_c + i] = true;
            *tur_c += step;
            break;
        case 1:
            for(int i = 1; i <= step; i++)
                floor[*tur_r + i][*tur_c] = true;
            *tur_r += step;
            break;
        case 2:
            for(int i = 1; i <= step; i++)
                floor[*tur_r][*tur_c - i] = true;
            *tur_c -= step;
            break;
        case 3:
            for(int i = 1; i <= step; i++)
                floor[*tur_r - i][*tur_c] = true;
            *tur_r -= step;
            break;
    }
}
void print(bool floor[][20]){
    cout << endl;
    cout << "HERE is the answer" << endl;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(floor[i][j] == false)
                cout << setw(3) << " ";
            else
                cout << setw(3) << "1";
        }
        cout << endl;
    }
}
