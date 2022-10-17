#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person* left, * right;
	string first, last;
    double num; 
	int height;
	Person(string fi, string l, double n) {
		first = fi;
        last = l;
        num = n;
		height = 1;
		left = NULL;
		right = NULL;
	}
};


#endif // !NODE_H