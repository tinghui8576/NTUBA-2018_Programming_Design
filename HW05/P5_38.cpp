//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-12
//  FILENAME   : P5_38.CPP
//  DESCRIPTION   : This is a program of tower of hanoi
//============================

#include <iostream>
#include <fstream>

using namespace std;

void hanoi(ofstream&, int, int, int, int);  //the function of moving hanoi
void outfilecheck(ofstream&);   //to check if the file be made succeessfully

int cnt = 0;    //the times that move stacks
int main() {
    ofstream output;    //output for the file
    output.open("message.txt"); //output file's name
    outfilecheck(output);   //check the file is open or not
    
    int stack = 3;    //the number of peg
    cout << "The way to move " << stack << " stacks is :" << endl;
    output << "The way to move " << stack << " stacks is :" << endl;
    hanoi(output, stack, 1, 2, 3);    //let the hanoi start at the first peg, the second peg is for temporary and the third one is the goal
    cout << "\nThe total moves is " << cnt << " times. "<< endl;
    output << "\nThe total moves is " << cnt << " times. "<< endl;
    
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

void hanoi(ofstream& output, int num , int place, int temp, int goal){
    //if the stack is the last one, move it from place to goal
    if(num == 1){
        cout << place << " -> " << goal <<endl;
        output << place << " -> " << goal <<endl;
        cnt++;  //add the time of move
    }
    else{
        hanoi(output, num-1, place, goal, temp);    //move the upper stacks to the temporary peg
        hanoi(output, 1, place, temp, goal);    //move the one to the goal
        hanoi(output, num-1, temp, place, goal);    //move the upper stacks to the goal peg
    }
}
