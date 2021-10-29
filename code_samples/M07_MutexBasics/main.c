#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10000

struct data_node {
    int data;
    struct data_node* next;
};

struct data_node* list_head = NULL;
pthread_mutex_t list_lock;

void addFront(int data) {
    struct data_node* node = (struct data_node*)malloc(sizeof(struct data_node));

    node->data = data;

    pthread_mutex_lock(&list_lock);
        node->next = list_head;
        list_head = node;
    pthread_mutex_unlock(&list_lock);
}

void display_list() {
    struct data_node* iter = list_head;
    int count = 0;

    while(iter != NULL ){
        printf("Node: data=%d\n", iter->data);
        count++;
        iter = iter->next;
    }

    printf("Node Count: %d", count);
}

void* runner_create_arg_node(void* arg) {

    int data = (int)arg;

    struct timespec wait_time;
    wait_time.tv_sec = 0;

    wait_time.tv_nsec = rand() % 100000 + 100000;
    nanosleep(&wait_time, NULL);

    addFront(data);

    pthread_exit(0);
}

int main() {
    pthread_t tids[NUM_THREADS];

    srand(time(NULL));

    pthread_mutex_init(&list_lock, NULL);

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_create(&tids[i], NULL, runner_create_arg_node, (void *) i);

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(tids[i], NULL);

    display_list();

    pthread_mutex_destroy(&list_lock);

    return 0;
}