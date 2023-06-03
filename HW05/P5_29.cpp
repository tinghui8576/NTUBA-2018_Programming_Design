//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-12
//  FILENAME   : P5_29.CPP
//  DESCRIPTION   : This is a program of prime numbers
//============================
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool primenumber(int);  //determine whether a number is prime
void outfilecheck(ofstream&);   //to check if the file be made succeessfully

int main() {
    ofstream output;    //output for the file
    output.open("message.txt"); //output file's name
    outfilecheck(output);   //check the file is open or not
    
    cout << "The prime numbers between 2-10000 :" << endl;
    output << "The prime numbers between 2-10000 :" << endl;
    for(int i = 2; i <= 10000; i++){
        bool prime = primenumber(i);    //store the bool of checking the prime number
        if(prime == true){
            //output the prime number on screen and file
            cout << i << " ";
            output << i << " ";
        }
    }
    return 0;
}

//check if it is prime number
bool primenumber(int num){
    bool flag = true;   //set the bool to true first
    
    for(int i = 2; i <= sqrt(num); i++){
        //if it can be modify by any number, change the bool to false which means it is not prime number
        if(num % i == 0){
            flag = !flag;
            break;
        }
    }
    return flag;
}

void outfilecheck(ofstream& output){
    if(output.fail()){
        cout << "The file doesn't be made successfully!"<< endl << endl;
        exit(1);
    }
    cout << "The file has be made succeessfully!" << endl <<endl;
}

