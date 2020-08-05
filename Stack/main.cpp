#include<iostream>
#include<algorithm>
#include"ArrayStack.cpp";
#define INIT_STACK_CAPACITY 1
using namespace std;

int main() {

    Array_Stack* pIntArrayStack;
    int* pData;

    printf("Initializing integer stack of capacity(%d)\n", INIT_STACK_CAPACITY);
    pIntArrayStack = (Array_Stack*)calloc(sizeof(Array_Stack), 1);
    pIntArrayStack = initStack(pIntArrayStack, INIT_STACK_CAPACITY);
    printStack(pIntArrayStack);
    printf("\nPushing data into integer stack:\n");
    for (size_t i = 0; i < 10; i++)
    {
        push(pIntArrayStack, i);
        printStack(pIntArrayStack);

    }
    printf("\nPoping data from integer stack:\n");
        for (size_t i = 0; i < 10; i++)
        {
            pData = top(pIntArrayStack);
            if (pData != NULL)
                printf("Current top is = %3d: ", *pData);
            pData = pop(pIntArrayStack);
            if (pData != NULL)
                printf("==> poped data = %ed\n", *pData);
            printStack(pIntArrayStack);
        }


    return 0;
}

