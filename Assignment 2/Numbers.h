#ifndef MULTITHREADING_NUMBERS_H
#define MULTITHREADING_NUMBERS_H


class Numbers {
private:
    int size;
    int *myarray;
    int sum;

public:
    // Default constructor
    Numbers();
    // Parameterized constructor
    Numbers(int size);
    // Destructor
    ~Numbers();
    // Getters and setters
    int getSize() const;

    void setSize(int value);

    int *getMyarray() const;

    void setMyarray(int arrSize);

    int getSum() const;

    void setSum(int value);

};



#endif //MULTITHREADING_NUMBERS_H
