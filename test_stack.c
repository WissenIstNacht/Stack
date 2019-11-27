/******************************************************************************
 * Author: WissenIstNacht 
 * Date: November 2019
 *
 * This program tests the different functions provided by the stack module.
 *
******************************************************************************/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void basic_test(){
    pStack s = createStack();
    print(s);
    push(1, s);
    print(s);
    push(2, s);
    print(s);
    peek(s);
    print(s);
    pop(s);
    print(s);
    peek(s);
    print(s);
    pop(s);
    print(s);
    for (size_t i = 0; i < 5; i++){
        push(i, s);
    }
    print(s);
    clear(s);
    print(s);
    remove_stack(s);
}

int main(int argc, char const *argv[]){
    basic_test();
    return 0;
}
