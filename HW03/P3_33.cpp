//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/21
//  FILENAME   : P3_33.CPP
//  DESCRIPTION   : This is a program of 3.33 sides of a right triangle
//=============================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int side = 0;   //store the side
    cout << "Please input three side of a triangle." << endl;
    
    int lside = 0, mside = 0, sside = 0;    //store the largest, middle and smallest side
    
    for(int i = 0; i < 3; i++){
        cin >> side;
        
        while(side == 0){   //check if the side is 0
            cout << "The side can't be 0, please input another number! " << endl;
            cin >> side;
        }
        
        //put side in to largest side, middle side and smallest side
        if(lside < side){
            sside = mside;
            mside = lside;
            lside = side;
        }
        else if(mside < side){
            sside = mside;
            mside = side;
        }
        else if(sside < side)
            sside = side;
    }
    
    //check if it is a right triangle
    if(pow(sside,2)+pow(mside,2) == pow(lside,2))
        cout << "It's a right triangle" << endl;
    else
        cout << "It's not a right triangle." << endl;
    
    return 0;
}
