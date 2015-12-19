#pragma once

struct Stack;

Stack *createStack();

void push(int x, Stack *stack);

int pop(Stack *stack);

void showResult(Stack *stack);

void delStack(Stack *&stack);