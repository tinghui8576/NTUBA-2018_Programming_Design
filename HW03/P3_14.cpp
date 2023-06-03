//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/19
//  FILENAME   : P3_14.CPP
//  DESCRIPTION   : This is a program of 3.14 Credit limit calculator
//=============================

#include <iostream>

using namespace std;

int main() {
    int account = 0;
    
    cout << "Enter account number (or -1 to quit): " ; //tell the user to input account number
    while(cin >> account){
        if (account == -1)
            break;
        else{
            double bbalance = 0.0, charge = 0.0, credit = 0.0, nbalance = 0.0, limit = 0.0;
            
            cout << "Enter beginning balance : " ; //input beginning balance
            cin >> bbalance;
            cout << "Enter total charges : " ;  //input total charges
            cin >> charge;
            cout << "Enter total credits : ";   //input total credits
            cin >> credit;
            cout << "Enter credit limit : "; //input credit limit
            cin >> limit;
            
            nbalance = bbalance + charge - credit;
            cout << "New balance is " << nbalance << endl;  //output the new balance
            
            if(limit < nbalance)    //check if the new balance is exceeded the limit
                cout << "Credit Limit Exceeded" << endl;
            cout << "\nEnter account number (or -1 to quit): " ; //tell the user to input account number
        }
        
    }
    
    return 0;
}
