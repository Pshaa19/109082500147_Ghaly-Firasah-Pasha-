#include "stack1.h"

void CreateStack(Stack &S) {
    S.top = 0;
}

void createStack(Stack &S) {
    CreateStack(S);
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top = S.top + 1;
        S.info[S.top] = x;
    }
}

void Push(Stack &S, infotype x) {
    push(S, x);
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top > 0) {
        x = S.info[S.top];
        S.top = S.top - 1;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    CreateStack(temp);
    while (S.top > 0) {
        push(temp, pop(S));
    }
    S = temp;
}