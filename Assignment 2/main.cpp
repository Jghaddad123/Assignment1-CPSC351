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

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, do_work,NULL);
        pthread_join(threads[i], NULL);
    }
    return 0;
}




/* TODO:
This user-defined function is used by each thread accessing unique 4th part of the dynamic array.
The result from this function is written into the private sum variable.
Since all threads update a shared variable sum within the class, you are required to use the mutex variable for race conditions prevention.
Yes, this function header needs to stay the same; otherwise, the challenge is not so “challenging”.
*/
void *do_work(void *arg) {
int sum = 0;
    // Each thread computes sum of 1/4th of array
    if (MyNumbers.getMyarray() != nullptr) {
        int *end = MyNumbers.getMyarray() + MyNumbers.getSize();
        for (int *it = MyNumbers.getMyarray(); it != end; it++) {


            int thread_part = pthread_self();

            for (int i = thread_part * (MyNumbers.getSize() / 4); i < (thread_part + 1) * (MyNumbers.getSize() / 4); i++)
                sum += *it;



         }
 cout<<endl<<sum <<endl;
    }
}
