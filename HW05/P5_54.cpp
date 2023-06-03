//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-12
//  FILENAME   : P5_54.CPP
//  DESCRIPTION   : This is a program of template for maximum
//============================

#include <iostream>
#include <fstream>

using namespace std;

void outfilecheck(ofstream&);   //to check if the file be made succeessfully

template <class C>  //template for finding maximum between two data 
C maxi(C num1, C num2){
    C maxi = num1;
    
    if(num2 > maxi)
        maxi = num2;
    
    return maxi;
}

int main() {
    ofstream output;    //output for the file
    output.open("message.txt"); //output file's name
    outfilecheck(output);   //check the file is open or not
    
    //find the maximum in integers
    int int1, int2;
    cout << "Enter two integers and it will show the maximum : ";
    cin >> int1 >> int2;
    cout << "The maximum between " << int1 << " and " << int2 << " is ";
    cout << maxi(int1, int2) << endl;
    output << "The maximum between " << int1 << " and " << int2 << " is ";
    output << maxi(int1, int2) << endl;
    
    //find the maximum in characters
    char char1, char2;
    cout << "Enter two characters and it will show the maximum : ";
    cin >> char1 >> char2;
    cout << "The maximum between " << char1 << " and " << char2 << " is ";
    cout << maxi(char1, char2) << endl;
    output << "The maximum between " << char1 << " and " << char2 << " is ";
    output << maxi(char1, char2) << endl;
    
    //find the maximum in floating-point number
    float flo1, flo2;
    cout << "Enter two floating-point number and it will show the maximum : ";
    cin >> flo1 >> flo2;
    cout << "The maximum between " << flo1 << " and " << flo2 << " is ";
    cout << maxi(flo1, flo2) << endl;
    output << "The maximum between " << flo1 << " and " << flo2 << " is ";
    output << maxi(flo1, flo2) << endl;
    
    return 0;
}

//check the file is made successfully or not
void outfilecheck(ofstream& output){
    if(output.fail()){
        cout << "The file doesn't be made successfully!"<< endl << endl;
        exit(1);
    }
    cout << "The file has be made succeessfully!" << endl <<endl;
}

