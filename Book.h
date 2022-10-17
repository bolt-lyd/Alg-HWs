#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Person.h"
using namespace std;

class Book {
private:
	Person* root;
	int NumNode = 0;
	void ClearTree(Person* t);
	void Print(Person* t);
	void rRotate(Person* gp, Person* p);
	int max(int a, int b);
	void lRotate(Person* gp, Person* p);
	int getBalance(Person* n);
public:
	Book();
	~Book();
	void Add(string fi, string l, double n);
	double Find(string fi, string l);
	int TreeSize();
	void EmptyTree();
	void Delete(string fi, string l);
	void Change(string fi, string l, double n);
	void PrintTree();
	int getHeight(Person* temp);
	void Display();
	void Quit();
};

#endif // !TREE_H