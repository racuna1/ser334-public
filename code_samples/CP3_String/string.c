#include "string.h"

struct string {
    char* contents;
    int length;
};

//helper function
int length(char* str) {
    int count = 0;
    while (*(str++) != 0)
        count++;
    return count;
}

string string_create(char* str) {
    string s = malloc(sizeof(string));
    s->length = length(str);
	s->contents = malloc(s->length);
	
	//copy char array
	int i;
	for (i = 0; i < s->length; i++) {
		s->contents[i] = str[i];
	}
	
    return s;
}

void string_destroy(string str) {
    free(str->contents);
    free(str);
}

void string_append(string str, char* app) {
    char* buff = malloc(str->length + length(app) + 1);
    int i;
    for (i = 0; i < str->length; i++)
        buff[i] = str->contents[i];
    for (i = 0; i < length(app); i++)
        buff[i + str->length] = app[i];
    buff[i + str->length] = '\0';
    free(str->contents);
    str->contents = buff;
    str->length = length(buff);
}

string string_substring(string str, int start, int end) {
    int size = end - start;
    char* new_str = malloc(size);
    int i;
    for (i = 0; i < size; i++)
        new_str[i] = str->contents[start++];
    new_str[i] = '\0';
    string result = malloc(sizeof(string));
    result->contents = new_str;
    result->length = length(new_str);
    return result;
}

int string_length(string str) {
    return str->length;
}

void string_display(string str) {
    printf("%s\n", str->contents);
}