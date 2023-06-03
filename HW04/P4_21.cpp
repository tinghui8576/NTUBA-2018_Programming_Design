//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/4/07
//  FILENAME   : P4_21.CPP
//  DESCRIPTION   : This is a program of 4.21 of calculating salaries
//=============================

#include <iostream>
using namespace std;

int main() {
    int person; //store which kind of person you want
    
    cout << "Please enter which kind of employee's weekly pay you want to know:"<<endl;
    cout <<"Manager: 1\tHourly worker:2\tCommission worker:3\tpieceworker:4\tquit:5" << endl;
    //let the user know what they should input
    
    while(cin >>person){
        bool quit = false;  //check if the user want to quit
        int pay = 0;    //store the answer of the employee's weekly pay
        int weekly = 0; //store the manager's weekly salary
        int hourly = 0; //store the worker's hourly wage
        int time = 0;   //store the worker's working time
        int sales = 0;  //store the gross weekly sales
        int piece = 0;  //store the pieces the worker make
        int item = 0;   //store the money per piece
        
        switch (person) {
            case 1: //the manager
                cout << "How much is this manager's weekly salary?" << endl;
                cin >> weekly;
                pay = weekly;   //weekly pay equals to the weekly salary
                break;
                
            case 2: //the hourly worker
                cout << "How much is this worker's hourly wage?" << endl;
                cin >> hourly;
                cout << "How long he/she works?" << endl;
                cin >> time;
                if(time <= 40)
                    pay = hourly * time;    //weekly pay equals to the hourly pay times the time worker do if the time is not up to 40
                else
                    pay = hourly * 40 + hourly * 1.5 * ( time - 40 );   //weekly pay equals to the hourly pay times  40 and 1.5 time their hourly wage if more than 40 hours
                break;
                
            case 3: //Commission worker
                cout << "How much the gross weekly sales is?" << endl;
                cin >> sales;
                pay = 250 + 0.057 * sales;  //the pay is equal to 250 plus the gross weekly sales times 5.7 percent
                break;
                
            case 4: //pieceworker
                cout << "How much the money he/she can get per item?" << endl;
                cin >> item;
                cout << "How many item he/she produces?" << endl;
                cin >> piece;
                pay = item * piece; //the pay is equal to the pieces worker made times the money per item
                break;
                
            case 5: //quit
                quit = true;
                break;
        }
        
        if(quit == true)
            break;  //quit
        
        cout << "The weekly pay for this employee is " << pay << endl << endl;
        //output the wage
        
        cout << "Please enter which kind of employee's weekly pay you want to know:" << endl;
        cout << "Manager: 1\tHourly worker:2\tCommission worker:3\tpieceworker:4\tquit:5" << endl;
        //let the user know what they should input
    }
    return 0;
}
