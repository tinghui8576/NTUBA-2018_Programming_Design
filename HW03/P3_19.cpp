//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/21
//  FILENAME   : P3_19.CPP
//  DESCRIPTION   : This is a program of 3.19 to find the two largest numbers
//=============================

#include <iostream>
using namespace std;
int main() {
    int counter = 0;    //store the time you input
    int largest = 0, slargest = 0;  //store the two largest numbers
    int check[10] = {0};    //store the number you input before
    
    cout << "Please give me 10 numbers."<< endl;
    
    while(counter < 10){    //check if you give 10 numbers
        int number = 0; //input number
        cin >> number;
        counter++;  //add the times you input
        check[counter] = number;    //store the number in your input before in to an array
        for(int i = 0; i < counter; i++){
            if(check[i] == number){ //check if there is any same number
                cout << "That is the same number as you input before, try another number! " << endl;
                counter --;
            }
            
        }
        
        if(largest < number){   //put the largest number in to the largest and put the second to the slargest
            slargest = largest;
            largest = number;
        }
        else if(slargest < number)  //put the second to the slargest
            slargest = number;
    }
    
    //show the answer
    cout << "The largest number among the 10 numbers is " << largest << endl;
    cout << "The second large number among the 10 numbers is " << slargest << endl;
    
    return 0;
}
