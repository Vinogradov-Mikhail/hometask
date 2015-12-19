#pragma once

struct ElementList;

void addList(ElementList *&top, std::string const name, std::string const number, int const position); // add element in list

int readFile(ElementList *&top);// read file

void searchName(ElementList *top, std::string const name);// search name 

void searchNumber(ElementList *top, std::string const number);

void rewrite(ElementList *top); // rewrite our file

void deleteAll(ElementList *top);// delete all list


