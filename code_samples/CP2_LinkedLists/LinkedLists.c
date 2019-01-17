/* 
 * Examples of singly linked list operations for storing a user contact.
 * 
 * Author: Acuna
 * Version: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

struct ContactNode {
    char name[MAX_LEN];
    int phone;
    char email[MAX_LEN];
    
    struct ContactNode* next;
};


struct ContactNode* addFront(struct ContactNode* node, struct ContactNode* front) {
    node->next = front;
    front = node;
    
    return front;
}


struct ContactNode* removeFront(struct ContactNode* front) {
    if(front != NULL) {
        struct ContactNode* temp = front;
        front = front->next;
        free(temp);
    }
    
    return front;
}


struct ContactNode* selectByName(char* name, struct ContactNode* front) {
    struct ContactNode* prev = NULL;
    struct ContactNode* iter = front;
    
    while(iter != NULL) {
        if(strcmp(iter->name, name) == 0)
            return prev;
        else {
            prev = iter;
            iter = iter->next;
        }
    }
    
    return NULL;
}


void display(struct ContactNode* front) {
    struct ContactNode* iter = front;
    
    while(iter) {
        printf("name: %s phone: %d\n", iter->name, iter->phone);
        iter = iter->next;
    }
}


int main(int argc, char** argv) {
    
    struct ContactNode* n1 = (struct ContactNode*) malloc(sizeof(struct ContactNode));
    strcpy(n1->name, "Wonderbread");
    n1->phone = 1337;
    
    struct ContactNode* n2 = (struct ContactNode*) malloc(sizeof(struct ContactNode));
    strcpy(n2->name, "Test");
    n2->phone = 12345;
    
    struct ContactNode* n3 = (struct ContactNode*) malloc(sizeof(struct ContactNode));
    strcpy(n3->name, "Hello");
    n3->phone = 67890;    
    
    struct ContactNode* list = NULL;
    
    list = addFront(n1, list);
    list = addFront(n2, list);
    list = addFront(n3, list);
    
    display(list);
    
    struct ContactNode* sel = selectByName("Test", list);
    struct ContactNode* temp = sel->next;
    sel->next = sel->next->next;
    free(temp);
    
    display(list);
    
    //deallocate
    while(list != NULL)
        list = removeFront(list);
    
    return (EXIT_SUCCESS);
}