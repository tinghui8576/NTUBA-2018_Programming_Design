//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-12
//  FILENAME   : P5_49.CPP
//  DESCRIPTION   : This is a program of doing the craps and wager
//============================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void outfilecheck(ofstream&);   //to check if the file be made succeessfully
int dice();  //a function to roll two dice
void chatter(ofstream&);    //words before games start
void craps(int, int*, ofstream&);   //a function for the game

int main() {
    ofstream output;    //output for the file
    output.open("message.txt"); //output file's name
    outfilecheck(output);   //check the file is open or not

    srand(time(NULL));
    
    int bankBalance = 1000; //set the bank balance
    int wager = 0;  //set the wager
    
    while(bankBalance > 0){
        chatter(output);
        
        //input wager in each game
        cout << "Enter your wager : ";
        output << "Enter your wager : ";
        cin >> wager;
        output << wager << endl;
        
        //check the wager not be in unvalid
        while(wager <= 0){
            cout << "Wager shouldn't be equal or lower than 0, try another wager!" << endl;
            output << "Wager shouldn't be equal or lower than 0, try another wager!" << endl;
            cin >> wager;
            output << wager << endl;
        }
        while(wager > bankBalance){
            cout << "Sorry, your bank balance is lower than your wager.Please give a smaller wager." << endl;
            output << "Sorry, your bank balance is lower than your wager.Please give a smaller wager." << endl;
            cin >> wager;
            output << wager << endl;
        }
        
        craps(wager, &bankBalance, output); //start the game
        
        //output the bank balance in the end of the game
        cout << "Your bankBalance now is "<< bankBalance << endl << endl;
        output << "Your bankBalance now is "<< bankBalance << endl << endl;
        
    }
    
    //while the bankbalance is lower than 0 or equal to 0, means busted
    cout << "Sorry. You busted" << endl;
    output << "Sorry. You busted" << endl;
    
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

//the craps game
void craps(int w, int *bank, ofstream& output){
    bool state = true;  //store the state of wheather it ends or not
    bool game = false;  //store the state of wheather it wins or not
    
    int playerdice = dice();    //store the dice that throws
    int last = 0;   //store the first throws answer
    
    cout << "The player rolled : " << playerdice << endl;
    output << "The player rolled : " << playerdice << endl;
    
    //determine which dice number the throw is
    switch (playerdice) {
        //win when dice number is 7 or 11 at first time
        case 7:
        case 11:
            game = !game;   //change the state of game into wins
            state = !state; //change the state into end
            break;
            
        //lose when dice number is 2 or 3 or 11 at first time
        case 2:
        case 3:
        case 12:
            game = game;    //don't change the state of game when loses
            state = !state; //change the state into end
            break;
        
        //continue the game while the dice number is not the number above
        default:
            last = playerdice;  //store the first number
            break;
    }
    while(state == true){   //if it didn't win or lose, then continue
        playerdice = dice();    //store the dice that throws
        cout << "The player rolled : " << playerdice << endl;
        output << "The player rolled : " << playerdice << endl;
        
        //win when number it throw is the same as the first time
        if(playerdice == last){
            game = !game;   //change the state of game into wins
            state = !state; //change the state into end
        }
        //lose when number it throw is 7
        else if(playerdice == 7){
            game = game;    //don't change the state of game when loses
            state = !state; //change the state into end
        }
    }
    
    //determine is wins or loses
    if(game == true){
        cout << "Player wins!" << endl << endl;
        output << "Player wins!" << endl << endl;
        
        *bank = *bank + w;
    }
    else{
        cout << "Player loses!" << endl << endl;
        output << "Player loses!" << endl << endl;
        
        *bank = *bank - w;
    }
}

//throw two dice and send it back
int dice(){
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    
    return dice1+dice2;
}

//give some chatter before game start
void chatter(ofstream& output){
    int word = rand() % 3;
    switch (word) {
        case 0:
            cout << "Oh, you're going for broke, huh?" << endl;
            output << "Oh, you're going for broke, huh?" << endl;
            break;
        case 1:
            cout << "Aw cmon, take a chance!" << endl;
            output << "Aw cmon, take a chance!" << endl;
            break;
        case 2:
            cout << "You're up big.Now's the time to cash in your chips!" << endl;
            output << "You're up big.Now's the time to cash in your chips!" << endl;
            break;
    }
}
