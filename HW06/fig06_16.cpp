//============================
//  PROGRAMMER : Ting-Hui,Cheng
//  DATE       : 2019-5-28
//  FILENAME   : fig06_16.CPP
//  DESCRIPTION   : This is a program of fig06_16 with opening and writing file
//============================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int read_data();
void infilecheck(ifstream&);
void outfilecheck(ofstream&);

int main() {
    const int size = 50;
    int data[50] = {0};
    int sum = 0, sd = 0;
    ifstream input_data1, input_data2;
    input_data1.open("data1.txt");
    input_data2.open("data2.txt");
    infilecheck(input_data1);
    infilecheck(input_data2);
    ofstream output;
    output.open("data.txt");
    outfilecheck(output);
    
    cout << "Unsorted array :" << endl;
    output << "Unsorted array :" << endl;
    for(int i = 0; i < 20; i++){    //output unsort array1
        input_data1 >> data[i];
        sum += data[i];
        cout << setw(4) << data[i];
        output << setw(4) << data[i];
    }
    for(int i = 0; i < 30; i++){    //output unsort array2
        input_data2 >> data[i+20];
        sum += data[i+20];
        cout << setw(4) << data[i+20];
        output << setw(4) << data[i+20];
    }
    
    cout <<"\nSorted array :" << endl;
    output <<"\nSorted array :" << endl;
    
    //use insertion sort
    int insert;
    for(int index = 1; index < size; index++){
        insert = data[index];
        
        while((index > 0) && (data [index - 1] > insert)){
            data [index] = data [index - 1];
            index--;
        }
        
        data[index] = insert;
    }
    
    //output the sorted array
    for(int i = 0; i < 50; i++){
        cout << setw(4) << data[i];
        output << setw(4) << data[i];
        sd += pow(data[i] - (sum/50),2);
    }
    sd = sqrt(sd/50);
    cout << endl << endl;
    
    //output average value, standard deviation,median
    cout << "Average value in this data is " << sum / 50 << endl;
    cout << "Standard deviation in this data is " << sd << endl;
    cout << "Median in this data is " << ((double)data[24] + (double)data[25])/2 << endl;
    output << endl << endl;
    output << "Average value in this data is " << sum / 50 << endl;
    output << "Standard deviation in this data is " << sd << endl;
    output << "Median in this data is " << ((double)data[24] + (double)data[25])/2 << endl;
    return 0;
}

void infilecheck(ifstream& input){
    if(input.fail()){
        cout << "The file doesn't be opened successfully!"<< endl;
        exit(1);
    }
    cout << "The file has be opened succeessfully!" << endl;
}
void outfilecheck(ofstream& output){
    if(output.fail()){
        cout << "The file doesn't be made successfully!"<< endl << endl;
        exit(1);
    }
    cout << "The file has be made succeessfully!" << endl <<endl;
}
