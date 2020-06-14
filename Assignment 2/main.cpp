#include <iostream>
#include <pthread.h>
#include "Numbers.h"
using namespace std;

//global variable. All threads can access it.
Numbers MyNumbers;
const int NUM_THREADS = 4;
// Function prototypes
void *do_work(void *arg);

int main() {
    std::cout << "Hello, World!" << std::endl;
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
