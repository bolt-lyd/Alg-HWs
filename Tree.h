#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Node.h"
using namespace std;

class Tree {
private:
	Node* root;
	int NumNode = 0;
	void ClearTree(Node* t);
	void Print(Node* t);
	void rRotate(Node* gp, Node* p);
	int max(int a, int b);
	void lRotate(Node* gp, Node* p);
	int getBalance(Node* n);
public:
	Tree();
	~Tree();
	void Insert(string fi, string l, int n);
	int FindNum(string fi, string l);
	int TreeSize();
	void EmptyTree();
	void Remove(string fi, string l);
	void PrintTree();
	int getHeight(Node* temp);
	void PrintDiagram();
};

#endif // !TREE_H