//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-28
//  FILENAME   : P6_12.CPP
//  DESCRIPTION   : This is a program of bubble sort
//============================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int data[10] ={0};
    cout << "Please input 10 integers and it will sort it by bubble sort" << endl;
    
    
    for(int i = 0; i < 10; i++)
        cin >> data[i];
    
    //output the unsorted array
    cout << "Data before sorting :" << endl;
    for(int i = 0; i < 10; i++)
        cout << setw(7) << data[i];
    
    cout << endl;
    cout << "Data after sorting :" << endl;
    //using buuble sort
    for(int i = 9; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    //output the sorted array
    for(int i = 0; i < 10; i++)
        cout << setw(7) << data[i];
    return 0;
}
