//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/23
//  FILENAME   : P4_18.CPP
//  DESCRIPTION   : This is a program of 4.18 of number systems table
//=============================

#include <iostream>
#include <bitset>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    cout << setw(8) << "number" << setw(11) << "binary" << setw(8) << "octal" << setw(8) << "hex"<< endl;
    //output the catagory of this table
    
    for(int i = 1; i <= 256 ; i++){ //count to 256
        int num = i;
        long long int ans = 0;
        int count = 0;
        
        while(num >= 1){
            if(num % 2 == 1){   //if the number cannot be divided by 2, then the ans should add 1
                ans = ans + 1 * pow(10,count);
            }
            num = num / 2;
            count++;
        }
        //to calculate the number in binary
        
        cout << dec << setw(8) << i << setw(11) << ans; //output the number in decimal and binary
        cout << setw(8) << oct << i << setw(8) << hex << i <<endl ; //output the number in octal and hex
    }
    return 0;
}
