//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-4-28
//  FILENAME   : HW05A.CPP
//  DESCRIPTION   : This is a program of guessing suit and value
//============================
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int gen_value(); //give a random number of value
int  guess_value (int); //check the value and count the guessing times
int gen_suit(); //give a random number of suit
int  guess_suit (int);  //check the suit and count the guessing times


int main() {
    //randomize random generator using curren time
    srand(time(0));
    
    int suit = gen_suit();  //store the random number
    int ans_suit = guess_suit(suit); //let the user guess the suit and the computer check
    int value = gen_value();  //store the random number
    int ans_value = guess_value(value); //let the user guess the value and the computer check
    
    cout << "The answer is ";
    //determine the random number into suit and output
    switch (suit) {
        case 1:
            cout << "Club ";
            break;
        case 2:
            cout << "Diamond ";
            break;
        case 3:
            cout << "Heart ";
            break;
        case 4:
            cout << "Spade ";
            break;
    }
    //display the random number by the rule that problem gives
    switch (value) {
        case 1:
            cout << "A" << endl;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            cout << value << endl;
            break;
        case 11:
            cout << "J" << endl;
            break;
        case 12:
            cout << "Q" << endl;
            break;
        case 13:
            cout << "K" << endl;
            break;
    }
    
    //output the time that the user guess
    cout << "You guessed" << endl;
    cout << ans_suit << " times in suit, and " << endl;
    cout << ans_value << " times in value."<< endl;
    
    return 0;
}

int gen_suit(){
    //pick a random number between 1-4
    int suit = rand() % 4 + 1;
    
    return suit;    //end function gen_suit
}

int  guess_suit (int suit_target){
    int count = 0;  //store the time that the user try
    int guess = 0;
    
    cout << "1 = Club" << setw(15) << "2 = Diamond" << setw(15) << "3 = Heart" << setw(15) << "4 = Spade" <<endl;
    cout << "Please enter a number between 1-4 which indicates the suit: " << endl;
    cin >> guess;
    count++;
    
    //check if the suit is not the same. if not the same, then continue to guess util they are the same
    while(guess != suit_target){
        //don't that the user guess the number not in 1-4
        if(guess < 1 || guess > 4){
            cout << "\nIt's not a number between 1-4, please try again! " << endl;
            cin >> guess;
        }
        else{
            cout << "No, please try again!" << endl;
            cin >> guess;
            count++;
        }
    }
    cout << "Yes, that’s right!\n" << endl;
    
    return count;
}

int gen_value(){
    //pick a random number between 1-13
    int number = rand() % 13  + 1;
    
    return number;    //end function gen_suit
}

int  guess_value (int  value_target){
    int count = 0;  //store the time that the user try
    int guess = 0;  //store the number you quess
    
    cout << "Please enter a number between 1-13 of the value : " << endl;
    cin >> guess;
    count++;
    
    //check if the value is not the same. if not the same, then continue to guess util they are the same
    while(guess != value_target){
        //don't that the user guess the number not in 1-13
        if(guess < 1 || guess > 13){
            cout << "\nIt's not a number between 1-13, please try again! " << endl;
            cin >> guess;
        }
        else{
            if(guess > value_target)    //if the guessing number is too big
                cout << "No, the answer is smaller!" << endl;
            else if(guess < value_target)   //if the guessing number is too small
                cout << "No, the answer is larger!" << endl;
            
            cin >> guess;
            count++;
        }
    }
    cout << "Yes, that’s right!\n" << endl;
    
    return count;
}
