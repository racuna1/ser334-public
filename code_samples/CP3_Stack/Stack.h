/**
* Specification for a stack ADT.
*
* Completion time: 
*
* @author Ruben Acuna
* @version (a version number or a date)
*/

#ifndef STACK_H
#define STACK_H

////////////////////////////////////////////////////////////////////////////////
// Include Files
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Type Definitions
typedef struct stack stack;

////////////////////////////////////////////////////////////////////////////////
//Function Declarations

//purpose: creates a new stack and returns it.
//return: a pointer to a new stack.
stack* stack_create(); //can fail (due to memory)

//purpose: destroys a stack.
//return: n/a
void stack_destroy(stack** s);

//purpose: adds an element to the stack.
//return: n/a
void stack_push(stack* s, void* element);

//purpose: returns the most recently added stack element.
//return: a pointer to the element that has been removed.
void* stack_pop(stack* s); //can fail (if empty stack)

//purpose: returns true if the stack is empty, false otherwise.
//return value: boolean to indicate if empty.
int stack_is_empty(stack* s);

//purpose: returns the number of elements in the stack
//return: number of elements in the stack
int stack_size(stack* s);

//purpose: displays the contents of the stack as integers starting at the top.
//return: n/a
void stack_display(stack* s);

#endif