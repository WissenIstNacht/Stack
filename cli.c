/******************************************************************************
    Author: WissenIstNacht
    Date: November 2019 

    This Program/Module description

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char const *argv[])
{
    pStack s;
    while(!(s = createStack()));

    int exit = 0;
    while(!exit){
        printf("Type any of the following digits to perform the according action!\n");
        printf("1. Push element to the stack.\n");
        printf("2. Peek at the stack.\n");
        printf("3. Pop element from the stack.\n");
        printf("4. Clear the entire stack.\n");
        printf("5. Print the stack.\n");
        printf("6. Exit the program.\n");
        printf("$");

        int task;
        scanf("%i", &task);
        switch (task)
        {
        case 1:
            printf("Enter a key to push: \n");
            printf("$");
            
            int key;
            scanf("%i", &key);
            if(push(key, s)){
                printf("-> Key %i pushed! New stack size: %i\n", key, s->size);
            }else{
                printf("-> Error! No key was pushed...\n");
            }
            break;
        case 2:
            if(s->size == 0){
                printf("-> The stack is currently empty!\n");
            }else{
                int top = peek(s);
                printf("-> Top element is: %i\n", top);
            }
            break;
        case 3:
            if(s->size == 0){
                printf("-> The stack is currently empty!\n");
            }else{
                int top = pop(s);
                printf("-> Popped element contains key: %i\n", top);
            }
            break;
        case 4:
            printf("-> Stack cleared!\n");
            clear(s);
            break;
        case 5:
            print(s);
            break;
        case 6:
            printf("-> Exiting...\n");
            exit = 1;
            break;
        default:
            printf("-> Invalid input. Please enter one of the digits listed above!\n");
            break;
        }
        if(!exit){
            printf("\n Press ENTER to continue ...\n");
            getchar();
            char c;
            while ((c = getchar()) != '\n' && c != EOF) {};
        }
    }
    remove_stack(s);
    return 0;
}
