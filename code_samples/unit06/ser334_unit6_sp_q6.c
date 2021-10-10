#include <pthread.h>
#include <stdio.h>
 
int t1, t2, input;

void* runner(void *param) {
    int result, upper = (int)param;
    int a = 1, b = 1, c = 1;
    
    for (int i = 2; i < input-upper; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    if(upper == 1)
        t1 = c;
    else
        t2 = c;
    
    pthread_exit(0);
}
 
int main(int argc, char *argv[]) {
    pthread_t tid1, tid2;
    pthread_attr_t attr;
    input = 10;

    pthread_attr_init(&attr);	
    pthread_create(&tid1, &attr, runner, 1);
    pthread_create(&tid2, &attr, runner, 2);
	
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("result = %d\n", t1+t2);
}