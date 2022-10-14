#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* left, * right;
	string first, last;
    int num, height;
	Node(string fi, string l, int n) {
		first = fi;
        last = l;
        num = n;
		height = 1;
		left = NULL;
		right = NULL;
	}
};


#endif // !NODE_H