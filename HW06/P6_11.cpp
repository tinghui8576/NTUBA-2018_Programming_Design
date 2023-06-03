//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-28
//  FILENAME   : P6_11.CPP
//  DESCRIPTION   : This is a program of bubble sort to sort 10 integers
//============================

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    int data[10] ={0};
    cout << "Please input 10 integers and it will sort it by bubble sort" << endl;
    
    for(int i = 0; i < 10; i++)
        cin >> data[i];
    
    //output array before sorting
    cout << "The data before sorting:" << endl;
    for(int i = 0; i < 10; i++)
        cout << setw(8) << data[i];
    //bubble sort
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
     //output array after sorting
    cout << endl;
    cout << "The data after sorting :" << endl;
    for(int i = 0; i < 10; i++)
        cout << setw(8) << data[i];
    return 0;
}
