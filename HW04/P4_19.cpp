//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/4/07
//  FILENAME   : P4_19.CPP
//  DESCRIPTION   : This is a program of 4.19 of calculating pi
//=============================
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 4.0;    //store the answer of pi
    
    int  i = 1; //to store the Denominator
    int count = 1;  //count the time you do
    
    while(count<= 1000){
        i += 2; //as the formula, the Denominator should plus two each time
        cout << count;  //output the time you calculate
        
        if(count % 2 == 0)
            pi =  4.0 / i + pi;
        else
            pi = -4.0 / i + pi;
        //by the formula,if the count time is in two times, then it should minus the answer
        
        if(count < 1000)
            cout << "\t\t" ;
        else
            cout << "\t";
        //let the output be more beautiful
        cout << pi << endl; //output the answer
        count++;
    }
    
    return 0;
}
