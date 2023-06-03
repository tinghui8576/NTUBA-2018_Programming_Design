//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-12
//  FILENAME   : P5_41.CPP
//  DESCRIPTION   : This is a program of the greatest common divisor
//============================

#include <iostream>
#include <fstream>

using namespace std;

void outfilecheck(ofstream&);   //to check if the file be made succeessfully
int gcd(int, int);  //a function to get the greatest common divisor

int main() {
    ofstream output;    //output for the file
    output.open("message.txt"); //output file's name
    outfilecheck(output);   //check the file is open or not
    
    int x, y;
    cout << "Please input two numbers, it will show the greatest common divisor!" << endl;
    output << "Please input two numbers, it will show the greatest common divisor!" << endl;
    cin >> x >> y;
    output << x << " " << y << endl;
    
    //let x always bigger than y
    if ( x < y){
        int temp = x;
        x = y;
        y = temp;
    }

    int ans = gcd( x, y);   //store the ans from the function
    //output the ans
    cout << "The greatest common divisor between "<< x << " and " << y << " is " << ans << endl;
    output << "The greatest common divisor between "<< x << " and " << y << " is " << ans << endl;
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

//get the greatest common divisor
int gcd(int x, int y){
    if( y != 0)
        return gcd(y, x % y);
    else
        return x;
    //use  recursive and the formula to get the greatest common divisor
}
