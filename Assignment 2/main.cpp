#include <iostream>
#include <pthread.h>
#include "Numbers.h"
#include <mutex>
using namespace std;
#define NUM_THREADS 4

//global variable. All threads can access it.
Numbers MyNumbers;
mutex mtx;
// Function prototypes - threads call this function
void *do_work(void *arg);
// Thread attribute data
struct thread_data {
    int tid;
    int tSum;
};

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    struct thread_data threadAttr[NUM_THREADS];

    // Loop to create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        // Set thread attributes for each created thread.
        threadAttr[i].tid = i;
        threadAttr[i].tSum = 0;
        pthread_create(&threads[i], NULL, do_work, (void *)&threadAttr[i]);
    }

    // Join array of created children threads together
    for (int j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }
    cout << "Total Sum: " << MyNumbers.getSum() << endl;
    return 0;
}

/* TODO:
This user-defined function is used by each thread accessing unique 4th part of the dynamic array.
The result from this function is written into the private sum variable.
Since all threads update a shared variable sum within the class, you are required to use the mutex variable for race conditions prevention.
Yes, this function header needs to stay the same; otherwise, the challenge is not so “challenging”.
*/
void *do_work(void *arg) {
    struct thread_data *t_data;
    t_data = (struct thread_data *) arg;
    // Each thread computes sum of 1/4th of array
    if (MyNumbers.getMyarray() != nullptr) {
        int thread_part = (t_data->tid % NUM_THREADS);
        for (int i = thread_part * (MyNumbers.getSize() / NUM_THREADS); i < (thread_part + 1) * (MyNumbers.getSize() / NUM_THREADS); i++) {
            t_data->tSum += *(MyNumbers.getMyarray()+i);
        }

    }
    //mutex lock starts here to update the global sum in global Numbers instance
    mtx.lock();
    // update global sum for MyNumbers instance
    MyNumbers.setSum(MyNumbers.getSum() + t_data->tSum);
    //mutex unlock here so next thread can do work
    mtx.unlock();
    // terminate the thread
    pthread_exit(NULL);
}

