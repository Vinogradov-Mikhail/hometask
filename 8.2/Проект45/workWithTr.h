#pragma once
//#include "tree.h"

struct Trees;

void show(int ,Trees *);



void add(int, Trees *&);

bool search(int , Trees *);

Trees *&findMin(Trees *&);

void delElem(int ,Trees *&);

void delTree(Trees *&);
