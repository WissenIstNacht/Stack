#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

pStack createStack(){
    pStack new_stack = malloc(sizeof(stack));
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

int push(int key, pStack s){
    pElem new_elem = malloc(sizeof(elem));
    if (!new_elem) return 0;

    new_elem->key = key;
    new_elem->previous = s->top;
    s->top = new_elem;
    s->size++;
    return s->size;

}

int pop(pStack s){
    if(s->size == 0){
        fprintf(stderr, "Stack empty! Aborting...\n");
        exit(EXIT_FAILURE);
    }
    pElem curr_top = s->top;
    int res = curr_top->key;
    s->top = curr_top->previous;
    s->size--;
    free(curr_top);
    return res;
}

int peek(pStack s){
    if(s->size == 0){
        fprintf(stderr, "Stack empty! Aborting...\n");
        exit(EXIT_FAILURE);
    }
    return s->top->key;
}

void clear_stack(pStack s){
    pElem curr_elem = s->top;
    pElem prev_elem = s->top;
    
    while(s->size != 0){
        prev_elem = curr_elem->previous;
        free(curr_elem);
        s->size--;
        curr_elem = prev_elem;
    }
}

void remove_stack(pStack s){
    clear(s);
    free(s);
}

int* stack2Array(pStack s){
    int n = s->size;
    if (n == 0)   return NULL;

    int* new_arr = malloc(sizeof(int)*n);

    pElem curr_elem = s->top;
    for(int i = n-1; i >= 0; i--){
        new_arr[i] = curr_elem->key;
        curr_elem = curr_elem->previous;
    }
    return new_arr;
}

char* stack2String(pStack s){
    int n = s->size;

    if(n == 0){
        char* s = "||->//";
        char* out = malloc(6);
        for (int i = 0; i < 6; i++){
            out[i] = s[i];
        }
        return out;    
    }

    int* elems = toArray(s);

    char* buffer = malloc(16*n + 2);
    buffer[0] = '|';
    buffer[1] = '|';
    int offset = 2;

    for (size_t i = 0; i < n; i++){
        offset += sprintf(buffer + offset, "->[%i]", elems[i]);
    }
    
    return buffer;
}

void print_stack(pStack s){
    if(s->size == 0){
        printf("The stack is empty: %s\n", 
            toString(s));
    }else{
        printf("The stack contains %i elements: %s\n", 
            s->size, toString(s));
    }
}
