#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

////////////////////////////////////////////////////////////////////////////////
void* display_text(void* data) {
    printf("TEXT\n");
    printf("MORETEXT\n");
    pthread_exit(0);
}

void* compute_sum_firstn(void* data) {
    int sum = 0;
    int n = (int)data;

    for(int i = 0; i < n; i++)
        sum += i;

    printf("thread result: %d\n", sum);

    pthread_exit((void*)sum);
}

void demo_different_tasks() {
    pthread_t tid1, tid2;
    pthread_attr_t attr;
    int t2_output;

    pthread_attr_init(&attr);

    pthread_create(&tid1, NULL, display_text, NULL);
    pthread_create(&tid2, &attr, compute_sum_firstn, 5);
    pthread_join(tid1, NULL);
    pthread_join(tid2, &t2_output);

    printf("returned result: %d\n", t2_output);
}

////////////////////////////////////////////////////////////////////////////////
#define GLOBAL_THREAD_COUNT 3
struct point_2d {
    int x;
    int y;
};

struct point_2d global_data[GLOBAL_THREAD_COUNT];

void* display_text_global(void* data) {
    struct point_2d* point = (struct point_2d*)data;

    printf("Point: %d, %d\n", point->x, point->y);

    pthread_exit(0);
}

void demo_global_memory() {
    pthread_t tids[GLOBAL_THREAD_COUNT];

    for (int i = 0; i < GLOBAL_THREAD_COUNT; i++) {
        global_data[i].x = i + 1;
        global_data[i].y = i + 1;
    }

    pthread_t tid1, tid2;

    for(int i = 0; i < GLOBAL_THREAD_COUNT; i++)
        pthread_create(&tids[i], NULL, display_text_global, &global_data[i]);

    for(int i = 0; i < GLOBAL_THREAD_COUNT; i++)
        pthread_join(tids[i], NULL);
}

////////////////////////////////////////////////////////////////////////////////
struct point_2d* global_data_dyn;

void demo_global_memory_dynamic() {
    int thread_count = 3;
    pthread_t* tids = (pthread_t*)malloc(sizeof(pthread_t) * thread_count);

    global_data_dyn = (struct point_2d*)malloc(sizeof(struct point_2d) * thread_count);

    for (int i = 0; i < thread_count; i++) {
        global_data_dyn[i].x = i + 1;
        global_data_dyn[i].y = i + 1;
    }

    for(int i = 0; i < thread_count; i++)
        pthread_create(&tids[i], NULL, display_text_global, &global_data_dyn[i]);

    for(int i = 0; i < thread_count; i++)
        pthread_join(tids[i], NULL);
}

////////////////////////////////////////////////////////////////////////////////
struct thread_info {
    int start;
    int end;
    int* data;
    int result;
};

void* compute_partial_sum(void* data) {
    struct thread_info* info = (struct thread_info*)data;
    int sum = 0;

    for(int i = info->start; i < info->end; i++)
        sum += info->data[i];

    info->result = sum;

    pthread_exit(0);
}

void demo_compound_input() {
    pthread_t tids[2];
    struct thread_info infos[2];
    int data[] = {3, 3, 4, 2, 2, 2};
    int DATA_LENGTH = 6;

    pthread_t tid1, tid2;

    infos[0].start = 0;
    infos[0].end = DATA_LENGTH/2;
    infos[0].data = data;
    pthread_create(&tids[0], NULL, compute_partial_sum, &infos[0]);

    infos[1].start = DATA_LENGTH/2;
    infos[1].end = DATA_LENGTH;
    infos[1].data = data;
    pthread_create(&tids[1], NULL, compute_partial_sum, &infos[1]);

    pthread_join(tids[0], NULL);
    pthread_join(tids[1], NULL);

    printf("result: %d\n", infos[0].result);
    printf("result: %d\n", infos[1].result);
}

////////////////////////////////////////////////////////////////////////////////

void demo_thread_local_data() {
    pthread_t tids[2];
    struct thread_info** infos = (struct thread_info**)malloc(sizeof(struct thread_info*) * 2);
    int all_data[] = {3, 3, 4, 2, 2, 2};
    int DATA_LENGTH = 6;

    infos[0] = (struct thread_info*)malloc(sizeof(struct thread_info));
    infos[0]->start = 0;
    infos[0]->end = DATA_LENGTH/2;

    int* t1data = (int*)malloc(sizeof(int) * DATA_LENGTH / 2);
    for(int i = 0; i < DATA_LENGTH / 2; i++)
        t1data[i] = all_data[i];
    infos[0]->data = t1data;
    pthread_create(&tids[0], NULL, compute_partial_sum, infos[0]);

    infos[1] = (struct thread_info*)malloc(sizeof(struct thread_info));
    infos[1]->start = 0;
    infos[1]->end = DATA_LENGTH/2;

    int* t2data = (int*)malloc(sizeof(int) * DATA_LENGTH / 2);
    for(int i = DATA_LENGTH / 2; i < DATA_LENGTH; i++)
        t2data[i - DATA_LENGTH / 2] = all_data[i];
    infos[1]->data = t2data;

    pthread_create(&tids[1], NULL, compute_partial_sum, infos[1]);

    pthread_join(tids[0], NULL);
    pthread_join(tids[1], NULL);

    printf("result: %d\n", infos[0]->result);
    printf("result: %d\n", infos[1]->result);

    free(infos[0]->data);
    free(infos[1]->data);
    free(infos[0]);
    free(infos[1]);
    free(infos);
}

int main() {
    //demo_different_tasks();
    //demo_global_memory();
    //demo_global_memory_dynamic();
    //demo_compound_input();
    demo_thread_local_data();

    return 0;
}
