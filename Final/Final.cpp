//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-6-18
//  FILENAME   : finalexam.CPP
//  DESCRIPTION   : This is a program of least squares regression
//============================

#include <iostream>
#include <fstream>
#include <new>
#include <cmath>
#include <iomanip>
using namespace std;

void infilecheck(ifstream&);
int main ()
{
    int i,N;
    double *x, *y;
    double xsqr = 0.0, xy = 0.0, xsum = 0.0, ysum = 0.0;
    double m = 0.0, b = 0.0;
    
    ifstream input;
    input.open("coord.txt");
    infilecheck(input);
    
    input >> N;
    cout << "The number of points is " << N << endl;
    cout << endl;
    // get the number and output on screen
    
    x = new (nothrow) double[N];
    y = new (nothrow) double[N];
    //create x & y two dynamic array
    
    if (x == NULL || y == NULL)
        cout << "Error: memory could not be allocated";
    else{
        for (int i =0; i < N; i++){
            input >> x[i];
            input >> y[i];
            //input the file number into array
            
            xsqr = pow(x[i], 2) + xsqr;
            xsum = x[i] + xsum;
            ysum = y[i] + ysum;
            xy = x[i] * y[i] + xy;
            //do the calculation of the number need to use in least square regression
        }
        
        m = (N * xy- xsum * ysum) / (N * xsqr - pow(xsum, 2));
        b = (ysum - m * xsum) / N;
        //use the formula to calculate the m & b
        
        cout << "The first 5 coordinates are" << endl;
        cout << setw(15) << "x-axis" << setw(15) << "y-axis" << endl;
        for (int i = 0; i < 5; i++){
            cout << setw(15) << fixed << setprecision(6) << x[i] << setw(15) << y[i] << endl;
        }
        // output the first 5 coordinates
        cout << "\n\n";
        cout << "m = " << setw(11) << m << endl;
        cout << "b = " << setw(11) << b << endl;
        cout << endl;
        // output the slope and intercept
        
        delete[] x;
        delete[] y;
    }
    return 0;
}


void infilecheck(ifstream& input){
    if(input.fail()){
        cout << "The file doesn't be opened successfully!"<< endl;
        exit(1);
    }
    cout << "The file has be opened succeessfully!" << endl;
}
