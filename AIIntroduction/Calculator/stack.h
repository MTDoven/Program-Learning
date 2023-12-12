#pragma once
#include "define.h"


template <class T>
struct SqStack {
    T data[STACK_MAXSIZE];
    int top;
};


template <class T>
int initStack(struct SqStack<T>* S) {
    S->top = -1;
    return 1;
}

template <class T>
int getLength(struct SqStack<T>* S) {
    return (S->top) + 1;
}

template <class T>
int clearStack(struct SqStack<T>* S) {
    S->top = -1;
    return 1;
}

template <class T>
int isEmpty(struct SqStack<T>* S) {
    if (S->top == -1) return 1;
    else return 0;
}

template <class T>
int push(struct SqStack<T>* S, T e) {
    if (S->top == STACK_MAXSIZE - 1) {
        std::cout << "Stack overflow!\n";
        throw "Stack overflow!";
    }
    else {
        S->top++;
        S->data[S->top] = e;
        return 1;
    }
}

template <class T>
T pop(struct SqStack<T>* S) {
    if (S->top == -1) {
        std::cout << "Stack empty!\n";
        throw "Stack empty!";
    }
    else {
        T e = S->data[S->top];
        S->top--;
        return e;
    }
}

template <class T>
T getTop(struct SqStack<T>* S) {
    if (S->top == -1) {
        std::cout << "Stack empty!\n";
        throw "Stack empty!";
    }
    else {
        T e = S->data[S->top];
        return e;
    }
}

template <class T>
int printStack(struct SqStack<T>* S) {
    if (S->top == -1) {
        std::cout << "Stack empty!\n";
        throw "Stack empty!";
    }
    int i = 0;
    int p = S->top;
    while (p != -1) {
        i++;
        std::cout << "The " << i << "element from the top is: " << S->data[p] << "\n";
        p--;
    }
    return 1;
}