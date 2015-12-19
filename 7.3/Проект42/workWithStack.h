#pragma once

#include "stack.h"
#include <string>

void addElement(std::string, Stack*&);

void delElement(Stack);

bool check(Stack* , std::string );

void showResult(Stack*);

void delStack(Stack*&);