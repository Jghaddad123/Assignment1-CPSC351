#include <iostream>
#include <pthread.h>
#include "Numbers.h"
#include <pthread.h>

using namespace std;

//global variable. All threads can access it.
Numbers MyNumbers;
const int NUM_THREADS = 4;
// Function prototypes
void *do_work(void *arg);


int main(int argc, char *argv[]) {
   
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, do_work, NULL);
    }
    return 0;
}


void *do_work(void *arg) {
    cout << "size: " << MyNumbers.getSize() << endl;

    if(MyNumbers.getMyarray() != nullptr) {
        int count = 0;
        int *end = MyNumbers.getMyarray() + MyNumbers.getSize();
        for (int *it = MyNumbers.getMyarray(); it != end; it++) {
            cout << "*it: " << *it << endl;


// divides array by mod into 4 groups and match to a single thread then proceeds to add to sum
            if((count % 4 == 0) && (thread == threads[0])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            else if ((count % 4 ==1) && (thread ==threads[1])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            else if ((count % 4 ==2) && (thread ==threads[2])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            else if ((count % 4 ==3) && (thread ==threads[3])){
                MyNumbers.setSum(MyNumbers.getSum()+*it);
            }
            count++;
        }

    }













/* TODO:
This user-defined function is used by each thread accessing unique 4th part of the dynamic array.
The result from this function is written into the private sum variable.
Since all threads update a shared variable sum within the class, you are required to use the mutex variable for race conditions prevention.
Yes, this function header needs to stay the same; otherwise, the challenge is not so “challenging”.
*/

}
