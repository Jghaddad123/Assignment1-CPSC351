//
// Created by Beccs on 6/8/20.
//
#include "Numbers.h"
#include <iostream>
using namespace std;

// Default Constructor - will allocate a dynamic array with 4000
Numbers::Numbers() {
    cout << "default constructor is called" << endl;
    myarray = new int[10];
    for (int i = 0; i < 10; i++) {
        myarray[i] = int((rand() % 400 + 100)) /100;
        cout << myarray[i] << endl;
    }
}

// Parameterized constructor implementation which will allocate array based on given size
Numbers::Numbers(int size) : size(size) {
    myarray = new int[size];
}
// Destructor - release memory for myarray
Numbers::~Numbers() {
    cout << "Destructor is called" << endl;
    delete myarray;
}
// Getters and Setters
int Numbers::getSize() const {
    return size;
}

void Numbers::setSize(int value) {
    size = value;
}

int *Numbers::getMyarray() const {
    return myarray;
}

void Numbers::setMyarray(int arrSize) {
    myarray = new int[arrSize];
}

int Numbers::getSum() const {
    return sum;
}

void Numbers::setSum(int value) {
    sum = value;
}
