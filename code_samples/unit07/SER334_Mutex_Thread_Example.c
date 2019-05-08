/**
 * SER334 Mutex and Thread example code.
 * 
 * This program is designed to give a "real-world" example of how
 * mutexes and threads can be used together. There are three functions
 * that are shown in succession of one another, each providing a different
 * "view" in regards to potential use cases for mutex locks.
 * 
 * The examples in this program are based on a swimming pool where each 
 * function has different rules for the pool. Threads can be treated as
 * "swimmers" for the functionality of this program, with each thread being
 * an individual "swimmer" - these words can be used interchangeable for 
 * this program. 
 * 
 * These examples are by no means a rigorous rule set in how mutex locks
 * can (or should) be used. They are meant as a guideline to show some
 * ways that mutex locks can be used, you are encouraged to mess around with
 * the examples and figure more things out on your own!
 * 
 * @author Tony Conrad (tconrad2@asu.edu)
 * @version April 24, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// macros
#define THREAD_COUNT 4 // sets thread count, change this number if you want 
                       // to test with more threads (swimmers)

// global variables
int swimmer_count = 0; // count of swimmers in the pool at any given time
int max_count = THREAD_COUNT; // max count used for all_swim busy waiting
pthread_mutex_t swimmer_count_lock; // mutex lock for incrementing and 
                                    // decrementing swimmer count
pthread_mutex_t swimmer_lock; // mutex lock for swimmer in one_swim method

// forward declarations for functions
void* one_swim(void* args);
void* some_swim(void* args);
void* all_swim(void* args);

/**
 * Simulates swimmer (thread) joining and leaving a pool with output messages.
 * Only allows one swimmer in the pool at a time as they get out before
 * ever releasing the lock.
 * 
 * Uses mutex to only allow one swimmer in the pool at a time. Swimmer
 * performs all their swimming before releasing lock.
 * 
 * @param args integer value for swimmer's number
 * @return no return value
 */
void* one_swim(void* param){
    // swimmer gets in the pool, swims and leaves
    pthread_mutex_lock(&swimmer_lock); // grab swimmer count lock
    swimmer_count++; // increment swimmer count
    
    // cast user number from arguments
    int num = (int*) param;
    
    // display the number of swimmers in the pool
    printf("Swimmer %d got in pool, there are now %d swimmers in the pool.\n", 
            num, swimmer_count); 
    
    // "swimming" occurs here, only one thread is ever here at a time since
    // we are still inside the lock
    
    swimmer_count--; // decrement swimmer count
    
    // display the number of swimmers in the pool
    printf("Swimmer %d got out of the pool, there are now %d swimmers in the"
            " pool.\n", num, swimmer_count); 
    pthread_mutex_unlock(&swimmer_lock); // release swimmer count lock
    
    // exit thread
    pthread_exit(0);
}

/**
 * Simulates swimmer (thread) joining and leaving a pool with output messages.
 * Keeps count of number of swimmers in pool when each swimmer joins and leaves
 * and displays it.
 * 
 * Uses mutex to keep track of how many users are in the pool at any
 * given time. Gives a swimming delay to half the users to show that users can
 * get in and out in random order (does not have to be all in a row).
 * 
 * @param args integer value for swimmer's number
 * @return no return value
 */
void* some_swim(void* param){
    // swimmer gets in the pool
    pthread_mutex_lock(&swimmer_count_lock); // grab swimmer count lock
    swimmer_count++; // increment swimmer count
    
    // display the number of swimmers in the pool
    printf("New swimmer got in pool, there are now %d swimmers in the pool.\n", 
            swimmer_count); 
    pthread_mutex_unlock(&swimmer_count_lock); // release swimmer count lock

    // cast user number from arguments
    int num = (int*) param;
    
    // only add swimming delay to half of the swimmers, can try removing this
    // entirely to see what happens to the output
    if(num % 2 == 0) {
        usleep(1); // add artificial 'swimming' delay, mess around with 
                   // this number and see what changes in the output
    }       
    
    // swimmer gets out of the pool
    pthread_mutex_lock(&swimmer_count_lock); // grab swimmer count lock
    swimmer_count--; // decrement swimmer count
    
    // display the number of swimmers in the pool
    printf("Swimmer %d got out of the pool, there are now %d swimmers in the"
            " pool.\n", num, swimmer_count); 
    pthread_mutex_unlock(&swimmer_count_lock); // release swimmer count lock
    
    // exit thread
    pthread_exit(0);
}

/**
 * Simulates swimmer (thread) joining and leaving a pool with output messages.
 * Keeps count of number of swimmers in pool when each swimmer joins and leaves
 * and displays it. Uses busy waiting to ensure all swimmers get in before any
 * leave.
 * 
 * Uses a mutex to keep track of how many users are in the pool at any
 * given time. Uses busy waiting to ensure that the max number of users joins 
 * before any leave.
 * 
 * @param args integer value for swimmer's number
 * @return no return value
 */
void* all_swim(void* param){
    // swimmer gets in the pool
    pthread_mutex_lock(&swimmer_count_lock); // grab swimmer count lock
    swimmer_count++; // increment swimmer count
    
    // display the number of swimmers in the pool
    printf("New swimmer got in pool, there are now %d swimmers in the pool.\n", 
            swimmer_count); 
    pthread_mutex_unlock(&swimmer_count_lock); // release swimmer count lock

    // cast user number from arguments
    int num = (int*) param;
    
    // busy wait for all swimmers to join before letting any get out
    while(swimmer_count < max_count);
    // NOTE: busy waiting is generally not the greatest practice. Be very 
    // careful with this in implementation, can easily cause infinite loops.
    
    // swimmer gets out of the pool
    pthread_mutex_lock(&swimmer_count_lock); // grab swimmer count lock
    swimmer_count--; // decrement swimmer count
    max_count--; // decrement max count, since one swimmer got out
    
    // display the number of swimmers in the pool
    printf("Swimmer %d got out of the pool, there are now %d swimmers in the"
            " pool.\n", num, swimmer_count); 
    pthread_mutex_unlock(&swimmer_count_lock); // release swimmer count lock
    
    // exit thread
    pthread_exit(0);
}

/*
 * Main method, runs samples on all different method types.
 */
int main(int argc, char** argv) {
    pthread_t threads[THREAD_COUNT]; // create an array of pthreads, size of
                                     // THREAD_COUNT macro
    
    pthread_mutex_init(&swimmer_count_lock, NULL); // initialize swimmer count
                                                   // mutex lock
    
    pthread_mutex_init(&swimmer_lock, NULL); // initialize swimmer mutex lock
    
    // print to show start of this method
    printf("----------one_swim method----------\n\n");
    
    // initialize each thread in array to one_swim function with for loop 
    // increment value as an arg
    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, one_swim, i);
    }
    
    // processing inside function occurs...
    
    // wait for all threads to finish before moving on
    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // print to show end of this method
    printf("\n----------end one_swim method----------\n");
    
    // print to show start of this method
    printf("\n----------some_swim method----------\n\n");
    
    // initialize each thread in array to some_swim function with for loop 
    // increment value as an arg
    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, some_swim, i);
    }
    
    // processing inside function occurs...
    
    // wait for all threads to finish before moving on
    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // print to show end of this method
    printf("\n----------end some_swim method----------\n");
    
    // print to show start of this method
    printf("\n----------all_swim method----------\n\n");
    
    // initialize each thread in array to all_swim function with for loop 
    // increment value as an arg
    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, all_swim, i);
    }
    
    // processing inside function occurs...
    
    // wait for all threads to finish before moving on
    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // print to show end of this method
    printf("\n----------end all_swim method----------\n");
    
    pthread_mutex_destroy(&swimmer_count_lock); // destroy swimmer count lock
    pthread_mutex_destroy(&swimmer_lock); // destroy swimmer lock
    
    return EXIT_SUCCESS;
}
