#include "Numbers.h"
#include <iostream>
using namespace std;
const int ARRAY_SIZE = 40;
// Default Constructor - will allocate a dynamic array with 4000
Numbers::Numbers() {
    cout << "default constructor is called" << endl;
    size = ARRAY_SIZE;
    myarray = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        myarray[i] = int((random() % 400 + 100)) /100;
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
