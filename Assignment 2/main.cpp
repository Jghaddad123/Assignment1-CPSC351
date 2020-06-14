#include <iostream>
#include <pthread.h>
#include "Numbers.h"
using namespace std;
#define NUM_THREADS 4

//global variable. All threads can access it.
Numbers MyNumbers;
// Function prototypes - threads call this function
void *do_work(void *arg);

struct thread_data {
    int tid;
    int tSum;
};

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    struct thread_data threadAttr[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        threadAttr[i].tid = i;
        threadAttr[i].tSum = 0;
        pthread_create(&threads[i], NULL, do_work, (void *)&threadAttr[i]);
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
    struct thread_data *my_data;
    my_data = (struct thread_data *) arg;
    pthread_t threads[NUM_THREADS];
    *threads = reinterpret_cast<pthread_t>(arg);

    if (MyNumbers.getMyarray() != nullptr) {
        int count = 0;
        int *end = MyNumbers.getMyarray() + MyNumbers.getSize();
        for (int *it = MyNumbers.getMyarray(); it != end; it++) {

// divides array by mod into 4 groups and match to a single thread then proceeds to add to sum
            if((count % 4 == 0) && (my_data->tid == 0)) {
                cout << "it in if1: " << *it << endl;
                cout << "tsum if1: " << my_data->tSum << endl;
                my_data->tSum = (MyNumbers.getSum() + *it);
                cout << "tsum after add: " << my_data->tSum << endl;
                MyNumbers.setSum(my_data->tSum);
                cout << "Global Sum: "<< MyNumbers.getSum() << endl;
            }
            else if ((count % 4 == 1) && (pthread_self() == threads[1])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            else if ((count % 4 == 2) && (pthread_self() == threads[2])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            else if ((count % 4 == 3) && (pthread_self() == threads[3])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            count++;
        }

    }
    pthread_exit(NULL);
}

