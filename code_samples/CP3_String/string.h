#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>

// STRUCT DECLARATION
typedef struct string* string;

// FUNCTION DECLARATIONS
string string_create(char* str);
void string_destroy(string str);
void string_append(string str, char* app);
string string_substring(string str, int start, int end);
int string_length(string str);
void string_display(string str);

#endif