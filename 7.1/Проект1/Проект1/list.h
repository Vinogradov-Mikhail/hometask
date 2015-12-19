#pragma once
#include <string>

struct ElmentList;

void printList(ElmentList *book);

void push(ElmentList*& book, std::string name, int number);

int readFile(ElmentList*& book);

ElmentList* SortedMerge(ElmentList* first, ElmentList* last, int check);

void FrontBackSplit(ElmentList* book, ElmentList** front, ElmentList** back);

void MergeSort(ElmentList** mind, int variant);

void deleteList(ElmentList*& book);