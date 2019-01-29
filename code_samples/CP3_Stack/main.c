#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(int argc, char** argv) {
    
    stack* sid;
    
    sid = stack_create();  //like using "new"
    
    //stack ops: push, pop, display, etc.
    stack_push(sid, (void*)10);
    stack_push(sid, (void*)15);
    stack_push(sid, (void*)20);
    
    stack_display(sid);
    printf("The stack contains %d elements.\n", stack_size(sid));
    
    int x = (int)stack_pop(sid);
    stack_display(sid);
    printf("The stack contains %d elements.\n", stack_size(sid));
    printf("The popped value was %d\n", x);
    
    stack_pop(sid);
    stack_pop(sid);
    
    if(stack_is_empty(sid))
        printf("The stack is empty!\n");
    else
        printf("The stack is NOT empty!\n");
    
    stack_destroy(&sid);

    return (EXIT_SUCCESS);
}