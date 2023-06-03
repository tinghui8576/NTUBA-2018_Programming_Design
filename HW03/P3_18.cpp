//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/21
//  FILENAME   : P3_18.CPP
//  DESCRIPTION   : This is a program of 3.18 tabular output
//=============================

#include <iostream>
using namespace std;

int main() {
    int counter = 0;
    
    cout << "N\t" << "10*N\t" << "100*N\t" << "1000*N\t" << endl;
    while(counter < 5){
        cout << counter+1 << "\t" << (counter+1) * 10 << "\t\t" << (counter+1) * 100 << "\t\t"  << (counter+1) * 1000 <<endl;
        counter++;
    }
    return 0;
}
