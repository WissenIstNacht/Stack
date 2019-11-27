/******************************************************************************
 * Author: WissenIstNacht Date: November 2019
 *
 * This module implements a stack data structure. It provides basic
 * functionality such as creation, popping and pushing, as well as other handy
 * functions when working with stacks. So far, only integer keys are supported.
 *
 * How does one work with it? The module is meant to be used as follows:
 *
 * 1) Always start by creating a stack using the method createStack. This method
 *    returns a pointer to a stack (struct) with size 0 and ptrs set to NULL:
 *
 *    pStack someStack = createStack();
 *
 * 2) Then add or remove elements using the respective function: methods.
 *
 *    pop(42, someStack); 
 *    int top_elem = push(someStack); 
 *    remove();
 *
 * 3) Since stack elements are dynamically allocated delete stack after using
 *    it:
 *
 *    deleteStack(&someStack)
 *
******************************************************************************/


#ifndef STACK_H_
#define STACK_H_

typedef struct elem elem, *pElem;
struct elem{
    int key;
    pElem previous;
};

typedef struct{
    int size;
    pElem top;
}stack, *pStack;

/** Create empty stack structure.
 *
 * return
 * ------
 *  - Pointer to (empty) stack structure.
 *  - NULL if memory allocation failed.
 * 
 * Sets all fields null.
 */
pStack createStack();

/** Clears and deletes the stack.
 *
 * param
 * -----
 * s: pointer to stack.
 *
 * This method applies clear and then deletes the stack structure itself,
 * freeing all memory.
 */
void remove_stack(pStack s);

/** Insert item onto the top of the stack.
 *
 * param
 * -----
 *  - key:  new key to be inserted in stack.
 *  - s:    pointer to stack.
 *
 * return
 * ------
 *  - new stack size, if the insertion was successful,
 *  - 0, otherwise (e.g. no more mem, etc,)
 */
int push(int key, pStack s);

/** Returns and removes the stack's top element.
 * 
 * param
 * -----
 *  - s:   Pointer to stack.
 *
 * return
 * ------
 *  - The stack's top key.
 *
 * Popping from an emtpy stack will throw empty stack exception!
 */
int pop(pStack s);

/** Returns the stack's top element.
 * 
 * param
 * -----
 *  - s:   Pointer to stack.
 *
 * return
 * ------
 *  - The stack's top key.
 *
 * Peeking an emtpy stack will throw empty stack exception!
 */
int peek(pStack s);

/** Removes all elements from the stack.
 * 
 * param
 * -----
 *  - s:  pointer to stack.
 *
 * This method iterates through the stack, deleting each element. It frees the
 * memory of the allocated elements and sets the top pointer NULL.
 */
void clear(pStack s);

/** Outputs the stack as an array.
 *
 * param
 * -----
 *  - s: pointer to stack.
 *
 * return
 * ------
 * - Address to array,  if allocation successful
 * - NULL,              otherwise (e.g. no more mem, etc,)
 *
 * This method puts every key in the stack into an array. It does so by starting
 * at head and ending at tail.
 *
 *  [e_0, e_2, ..., e_n-1]
 * 
 * The stack must not be empty, as this makes the program throw an empty stack
 * exception.
 */
int* toArray(pStack s);

/** Returns a string representation of the stack.
 *
 * param
 * -----   
 *  - s: pointer to stack.
 *
 * return
 * ------
 *  - Pointer to array of chars holding the string.
 *
 * This method goes through the stack and produces a string representation
 * as follows:
 *
 *  "||->[e_1]->[e_2]->... ->[TOP]"
 */
char* toString(pStack s);

/** Prints the stack.
 *
 * param
 * -----
 *  - s: pointer to stack.
 *
 * Convenience function that prints the string returned by the toString
 * function.
 */
void print(pStack s);

#endif