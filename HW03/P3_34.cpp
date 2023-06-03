//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019/3/23
//  FILENAME   : P3_34.CPP
//  DESCRIPTION   : This is a program of 3.34 to caculate the factorial and e and e^x
//=============================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 0;
    
    //read a none negative int and computes its factorial
    cout << "Please input a n ans it will show the answer of n!." << endl;
    cin >> n;   //input a n number
    long long ans = 1;
    int count_f = 1;    //record the time of of doing factorial
    
    //don't let the n be a negative number
    while (n < 0){
        cout <<"n should be a non negative number, try another one!" << endl;
        cin >> n;
    }
    
    //doing the factorial
    if(n == 0)  //if n = 0, the factorial is 1
        cout <<"The factorial of " << n << "! is " << 1 << "."<< endl;
    else {
        cout <<"The factorial of " << n << "! is " ;
        
        //use the math formula to compute factorial
        while(count_f <= n){
            ans = ans * count_f;
            count_f++;
        }
        cout << ans << "."<< endl;  //output the answer
    }
    cout << endl;
    
    
    //estimate the value of the mathmatical constant e by using formula
    cout << "Please input a n ans it will show the answer of e and the n will be the accuracy." << endl;
    cin >> n;   //input a n number
    
    //don't let the n be a negative number
    while (n <= 0){
        cout <<"n should be a non negative number or 0, try another one!" << endl;
        cin >> n;
    }
    double ans_d = 1.0;    //store the answer in double number for the answer of e
    int count_times = 1;    //store the time it doing the calculation of e
    
    //caculate the e
    while(count_times <= n){
        count_f = 1;    //reset the time of doing the factorial because it's another caculation
        long long factorial = 1;  //store the answer of factorial you caculate
        
        //use the math formula to compute factorial
        while(count_f <= count_times){
            factorial = factorial * count_f;
            count_f++;
        }
        ans_d = ans_d + (double)1 / factorial;  //use the math formula to compute e
        count_times++;  //add the time you do the e
    }
    cout << "the answer of e when n is " << n << " is " << ans_d << endl; //output the answer
    cout << endl;
    
    
    //estimate the value of the mathmatical constant e^x by using formula
    int x = 0;
    cout << "Please input a x ans it will show the answer of e^x" << endl;
    cin >> x;
    cout << "Please input a n ans it will show the answer of e^x and the n will be the accuracy." << endl;
    cin >> n;
    
    //don't let the n be a negative number
    while (n <= 0){
        cout <<"n should be a non negative number or 0, try another one!" << endl;
        cin >> n;
    }
    ans_d = 1.0;    //reset the answer to store the answer of e^x
    count_times = 1;    //store the time it doing the calculation of e^x
    
    //caculate the e^x
    while(count_times <= n){
        count_f = 1;    //reset the time of doing the factorial because it's another caculation
        long long int factorial = 1;  //store the answer of factorial you caculate
        
        //use the math formula to compute factorial
        while(count_f <= count_times){
            factorial = factorial * count_f;
            count_f++;
        }
        ans_d = ans_d + (((double)pow(x,count_times)) / factorial); //use the math formula to compute e^x
        count_times++;  //add the time you do the e
    }
    cout << "the answer of e^x when n is " << n << " and x is " << x << " is " << ans_d << endl;   //output the answer
    cout << endl;
    
    return 0;
}
