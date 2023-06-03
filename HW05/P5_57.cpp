//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-14
//  FILENAME   : P5_57.CPP
//  DESCRIPTION   : This is a program of computer-assisted instruction
//============================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void outfilecheck(ofstream&);   //to check if the file be made succeessfully
int ques(bool, ofstream&);  //a function of making question
bool check(int, ofstream&); //a function of checking the answer
void res(bool, ofstream&);  //a function of response

int main() {
    ofstream output;    //output for the file
    output.open("message.txt"); //output file's name
    outfilecheck(output);   //check the file is open or not
    
    srand(time(NULL));
    
    bool cont = true;
    while(cont == true){    //to check if the user want to continue
        
        bool correct = true;    //check the answer is right or not
        int ans = 0;    //store the correct answer of question
        ans = ques(correct, output);    //get the correct answer from question function
        correct = check(ans, output);   //get the correctness from check function
        
        //if the answer from user is not correct, then continue asking the same question until correct
        while(correct == false){
            ans = ques(correct, output);
            correct = check(ans, output);
        }
        
        char conticheck;    //store the user input of whether it want to continue or not
        cout << "Do you want more question?" << endl;
        cout << "Y(y) for continue, N(n) for stop asking question" << endl;
        output << "Do you want more question?" << endl;
        output << "Y(y) for continue, N(n) for stop asking question" << endl;
        
        cin >> conticheck;
        output << conticheck << endl;
        
        //don't let user input the char out of y and n
        while(conticheck != 'Y' && conticheck != 'y' && conticheck != 'N' && conticheck != 'n'){
            cout << "Please input a character between Y and N!" << endl;
            cout << "Y(y) for continue, N(n) for stop asking question" << endl;
            output << "Y(y) for continue, N(n) for stop asking question" << endl;
            cin >> conticheck;
        }
        
        //if user answer y then continue to ask question, else stop ask
        if(conticheck == 'Y' || conticheck == 'y')
            cont = true;
        else if(conticheck == 'N' || conticheck == 'n')
            cont = false;
            
    }
    
    cout << "Bye bye!" << endl;
    output << "Bye bye!" << endl;
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

//a function of making question
int ques(bool correct, ofstream& output){
    //place store two number in question
    static int num1;
    static int num2;
    
    //if the answer from the user is correct
    if(correct == true){
        //get two random number
        num1 = rand() % 10;
        num2 = rand() % 10;
        cout << "How much is " << num1 << " times " << num2 << endl;
        output << "How much is " << num1 << " times " << num2 << endl;
        
        return num1 * num2;
    }
    else {  //if the answer from the user is wrong
        //ask the same question
        cout << "How much is " << num1 << " times " << num2 << endl;
        output << "How much is " << num1 << " times " << num2 << endl;
    
        return num1 * num2;
    }
}

//a function of checking the answer
bool check(int ans, ofstream& output){
    int studentans; //store the answer from user
    
    //let the user input their answer
    cin >> studentans;
    bool check = false;//store the correctness of the user input
    //if the user answer is correct then turn the state of check into true
    if(ans != studentans)
        check = false;
    else
        check = true;
    
    res(check, output); //get the response
    
    return check;
}

//response of what user input
void res(bool check, ofstream& output){
    int response = rand() % 4;
    
    if(check == true)   //when the answer is correct, randomly give an response
        switch (response) {
            case 0:
                cout << "Very good" << endl;
                output << "Very good" << endl;
                break;
            case 1:
                cout << "Excellent" << endl;
                output << "Excellent" << endl;
                break;
            case 2:
                cout << "Nice work!" << endl;
                output << "Nice work!" << endl;
                break;
            case 3:
                cout << "Keep up the good work!" << endl;
                output << "Keep up the good work!" << endl;
                break;
        }
    else    //when the answer is wrong, randomly give an response
        switch (response) {
            case 0:
                cout << "No. Please try again." << endl;
                output << "No. Please try again." << endl;
                break;
            case 1:
                cout << "Wrong. Try once more." << endl;
                output << "Wrong. Try once more." << endl;
                break;
            case 2:
                cout << "Don't give up!" << endl;
                output << "Don't give up!" << endl;
                break;
            case 3:
                cout << "No. Keep trying." << endl;
                output << "No. Keep trying." << endl;
                break;
        }
}
