//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/23
//  FILENAME   : P4_10.CPP
//  DESCRIPTION   : This is a program of 4.10 to caculate the factorials
//=============================

#include <iostream>
using namespace std;

int main() {
    long long int ans = 1;  //using long long int to prevent the answer being too long
    cout << "1!\t2!\t3!\t4!\t5!\t" << endl; //output the item of what you will show next
    for(int i = 1; i <= 5 ; i++ ){
        ans = ans * i;
        cout << ans << "\t" ;   //output the answer
    }
    cout << endl;
    
    return 0;
}
