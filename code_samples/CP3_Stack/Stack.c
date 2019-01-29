/**
* Implementation of a stack ADT.
*
* Completion time: 
*
* @author Ruben Acuna
* @version 1.0
*/

////////////////////////////////////////////////////////////////////////////////
// Include Files
#include "Stack.h"

////////////////////////////////////////////////////////////////////////////////
// Type Definitions

typedef struct node node;

struct node {
    void* element;
    node* next;
};

struct stack {
    node* head;
    int size;
};


////////////////////////////////////////////////////////////////////////////////
//Function Declarations

//purpose: creates a new stack and returns it.
//return: a pointer to a new stack.
stack* stack_create() {
    stack* new_stack = (stack*)malloc(sizeof(stack));
    
    //memory allocation failed
    if(new_stack == NULL) {
        printf("Failed to create stack.\n");
        exit(1);
    }
    //memory allocation succeeded 
    else {
        new_stack->head = NULL;
        new_stack->size = 0;
        
        return new_stack;
    }
}

//purpose: destroys a stack.
//return: n/a
void stack_destroy(stack** s) {
    node* iter = (*s)->head;
    
    //frees internal list
    while(iter != NULL) {
        node* n = iter->next;
        free(iter);
        iter = n;
    }
    
    //free stack
    free(*s);
    
    //clean up after ourselves ourside (no dangling pointer)
    *s = NULL;
}

//purpose: adds an element to the stack.
//return: n/a
void stack_push(stack* s, void* element) {
    node* new_node = (node*)malloc(sizeof(node));
    
    //set up node
    new_node->element = element;
    new_node->next = s->head;
    
    //attach node
    s->head = new_node;
    s->size++;
}

//purpose: returns the most recently added stack element.
//return: a pointer to the element that has been removed.
void* stack_pop(stack* s) {
    
    if(s->size == 0) {
        printf("Tried to pop from empty stack.\n");
        exit(1);
    }
        
    node* active_node = s->head;
    void* data = active_node->element;
    
    //update stack
    s->head = s->head->next;
    s->size--;
    
    return data;
}

//purpose: returns true if the stack is empty, false otherwise.
//return value: boolean to indicate if empty.
int stack_is_empty(stack* s) {
    return s->size == 0;
}

//purpose: returns the number of elements in the stack
//return: number of elements in the stack
int stack_size(stack* s) {
    return s->size;
}

//purpose: displays the contents of the stack as integers starting at the top.
//return: n/a
void stack_display(stack* s) {
    printf("(top):\n");
            
    node* iter = s->head;
    
    while(iter != NULL) {
        printf("%d\n", (int)iter->element);
        iter = iter->next;
    }
}