#include <iostream>
#include <pthread.h>
#include "Numbers.h"
using namespace std;
#define NUM_THREADS 4

//global variable. All threads can access it.
Numbers MyNumbers;
// Function prototypes - threads call this function
void *do_work(void *arg);


int main(int argc, char *argv[]) {
    cout << "size: " << MyNumbers.getSize() << endl;
    
    if(MyNumbers.getMyarray() != nullptr) {
        int *end = MyNumbers.getMyarray() + MyNumbers.getSize();
        for (int *it = MyNumbers.getMyarray(); it != end; it++) {
            cout << "*it: " << *it << endl;
        }

    }
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, do_work, NULL);
    }
    return 0;
}

void *do_work(void *arg) {
/* TODO:
This user-defined function is used by each thread accessing unique 4th part of the dynamic array.
The result from this function is written into the private sum variable.
Since all threads update a shared variable sum within the class, you are required to use the mutex variable for race conditions prevention.
Yes, this function header needs to stay the same; otherwise, the challenge is not so “challenging”.
*/
}

