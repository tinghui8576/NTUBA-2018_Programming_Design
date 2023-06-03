//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/4/07
//  FILENAME   : P4_23.CPP
//  DESCRIPTION   : This is a program of 4.23 of diamond of asterisks
//=============================

#include <iostream>
using namespace std;

int main() {
    
    bool blacheck = false;  //check if the blank is lower than 0
    int blank = 0;  //store the blank number
    int star = 0;   //store the star number
    
    for (int k = 0; k < 9; k++){
        if(4 - k < 0)   //check if the blank is lower than 0
            blacheck = true;
        
        if(blacheck == false)
            blank = 4-k;
        else
            blank = k-4;
        //if the blank number is lower than 0, than let it change to be bigger
        
        star = 5 - blank;
        
        for(int i = blank ; i > 0; i--)
            cout << " ";
        //output the blank
        
        for(int j = 0 ; j < 2*star-1; j++)
                cout << "*" ;
        //output the star
        
        cout << endl;
    }
    
    return 0;
}
