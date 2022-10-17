#pragma once
#define BOOK_H
#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

class Book {
private:
	Person* root;
	int NumNode = 0;
	void ClearBook(Person* t);
	void Print(Person* t);
	void rRotate(Person* gp, Person* p);
	int max(int a, int b);
	void lRotate(Person* gp, Person* p);
	int getBalance(Person* n);
	void PrintToFile(Person* t);
public:
	Book();
	~Book();
	void Add(string fi, string l, double n);
	double Find(string fi, string l);
	int BookSize();
	void EmptyBook();
	void Delete(string fi, string l);
	void Change(string fi, string l, double n);
	void Display();
	int getHeight(Person* temp);
	void Quit();
};
