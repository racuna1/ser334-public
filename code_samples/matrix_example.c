#include <stdio.h>
#include <stdlib.h>

//We need this to do use pthreads.
#include <pthread.h>

//Data structure for thread parameters.
//Wraps things up nicely for the thread to use.
typedef struct data{
    int *row;
    int *result;
    int columns;
} data_t;

//Method to pass into our thread.
//This will sort of act like the "main method" of each thread.
void addRows(void* param) {
    //"Unpack" the (void*) and treat it like a data_t struct
    data_t *data = (data_t*)param;

    *(data->result) = 0;

    //Add all the rows into result.
    int i;
    for(i = 0; i < data->columns; i++) {
        *(data->result) += data->row[i];
    }
    
}


int main() {

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int results[3];

    //Declare the structs we are going to need. One for each thread.
    data_t datum[3];
    //Declare the threads we are going to need. One for each row.
    pthread_t tid[3];


    int i;
    for(i = 0; i < 3; i++) {

        //Loop over our structs and set their variables.
        datum[i].result = &results[i];
        datum[i].row = matrix[i];
        datum[i].columns = 3;
        
        //Initialize our thread.
        //Give it the method and struct it should have
        pthread_create(&tid[i], NULL, addRows, &datum[i]);
    }


    for(i = 0; i < 3; i++) {

        //Loop over our threads and join them together.
        pthread_join(tid[i], NULL);

        //Print the results which should be stored in this array.
        printf("\nResult [%d]: %d\n", i, results[i]);
    }

    return 0;
}