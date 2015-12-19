#pragma once

struct ElementList;

void addList(ElementList *&, int);

int deleteList(ElementList *&top, int position);

void searchForDel(ElementList *&top, int value);

void sortList(ElementList *&);

void printList(ElementList *);

void deleteAll(ElementList *);


