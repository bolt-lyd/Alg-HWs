#include "Tree.h"
#include <iostream>
using namespace std;

//default constructor
Tree::Tree() {
	root = NULL;
}

//destructor - empty all items from tree
Tree::~Tree() {
	EmptyTree();
}

//takes string, finds correct place, inserts it
void Tree::Insert(string fi, string l, int n) {
	//checks root value and sets x as root if none
	if (root == NULL) {
		root = new Node(fi, l, n);
	}
	//if root there, finds new place
	else {
		//find
		Node* temp = root;
		Node* gp = temp;
		while ((temp->left != NULL && temp->last > l) ||
			(temp->right != NULL && temp->last < l)) {
			if (temp->last > l) {
				gp = temp;
				temp = temp->left;
			}
			else {
				gp = temp;
				temp = temp->right;
			}
		}
		//insert
		if (temp->last > l) {
			temp->left = new Node(fi, l, n);
		}
		else {
			temp->right = new Node(fi, l, n);
		}
		//update height of parent
		temp->height = 1 + max(getHeight(temp->left),
			getHeight(temp->right));
		//check balance
		int balance = getBalance(gp);
		//if not balance go through rotations
		//left left
		if (balance > 1) {
			rRotate(gp, temp);
		}
		//right right
		if (balance < -1) {
			lRotate(gp, temp);
		}
		/*//left right
		if (balance > 1 && x > temp->left->last) {
			temp->left = lRotate(temp->left);
		}
		//right left
		if (balance < -1 && x < temp->right->last) {
			temp->right = rRotate(temp->right);
		}*/
	}
	NumNode++;
}

//finds string, locats and returns string
//returns empty string if not found
int Tree::FindNum(string fi, string l) {
	Node* temp = root;
	while (temp != NULL && temp->last != l) {
		if (temp->last > l) {
			temp = temp->left;
		}
		else if (temp->last < l){
			temp = temp->right;
		}
        else{
            if (temp->first > fi){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
	}
	if (temp == NULL) {
		return NULL;
	}
	else {
		return temp->num;
	}
}

//returns number of items in tree
int Tree::TreeSize() {
	return NumNode;
}

 //removes all nodes with no memory leaks
void Tree::ClearTree(Node* t) {
	if (t == NULL) return;
	ClearTree(t->left);
	ClearTree(t->right);
	delete t;
}

void Tree::EmptyTree() {
	ClearTree(root);
}

//removes given string from tree and returns it
void Tree::Remove(string fi, string l) {

	Node* temp = root;
	//find int
	while ((temp->last > l && temp->left->last != l) ||
		(temp->last < l && temp->right->last != l)) {
		if (temp->last > l) {
			temp = temp->left;
		}
		else if (temp->last < l){
			temp = temp->right;
		}
        else{
            if (temp->first > fi){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
	}
	//string las;
	//root removal
	if (root->last == l) {
		//las = root->last;
		Node* temp2 = temp->left;
		//two children
		if ((temp->left != NULL) && (temp->right != NULL)) {
			Node* t = temp2;
			while (t->right != NULL) {
				t = t->right;
			}
			t->right = temp->right;
			t->left = temp->left;
			root = t;
		}
		//one child on left
		else if (temp->left != NULL) {
			root = temp->left;
		}
		//one child on right
		else if (temp->right != NULL) {
			root = temp->right;
		}
		//leaf
		else {
			root = NULL;
		}
		delete temp2;
	}
	if (temp->last > l) {
		//las = temp->left->last;
		Node* temp2 = temp->left;
		//two children
		if ((temp->left->left != NULL) && (temp->left->right != NULL)) {
			Node* t = temp2;
			Node* p = t;
			while (t->right != NULL) {
				p = t;
				t = t->right;
			}
			t->right = temp2->right;
			t->left->left = temp2->left;
			temp->left = t;
			p->right = NULL;
		}
		//one child on left
		else if (temp->left->left != NULL) {
			temp->left = temp->left->left;
		}
		//one child on right
		else if (temp->left->right != NULL) {
			temp->left = temp->left->right;
		}
		//leaf
		else {
			temp->left = NULL;
		}
		delete temp2;
	}
	else if (temp->last < l) {
		//las = temp->right->last;
		Node* temp2 = temp->right;
		//two children
		if ((temp->right->right != NULL) && (temp->right->left != NULL)) {
			Node* t = temp2;
			Node* p = t;
			while (t->left != NULL) {
				p = t;
				t = t->left;
			}
			t->left = temp2->left;
			t->right->right = temp2->right;
			temp->right = t;
			p->right = NULL; 
		}
		//one child on right
		else if (temp->right->right != NULL) {
			temp->right = temp->right->right;
		}
		//one child on left
		else if (temp->right->left != NULL) {
			temp->right = temp->right->left;
		}
		//no child
		else {
			temp->right = NULL;
		}
		delete temp2;
	}
	else {
		cout << "Value not found" << endl;
		//las = NULL;
		NumNode++;
	}
	NumNode--;
	delete temp;
	//return las;
}

//prints the tree in alphabetical order
void Tree::Print(Node* t) {
	if (t == NULL) return;
	Print(t->left);
	cout << t->last << endl;
	Print(t->right);
}

void Tree::PrintTree() {
	Print(root);
}

//gets height of specific nodes of tree
int Tree::getHeight(Node* temp) {
	if (temp == NULL) {
		return 0;
	}
	else {
		return temp->height;
	}
}

//max of two ints
int Tree::max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

//rotates tree to right 
//from given node
void Tree::rRotate(Node* gp, Node* p) {
	Node* pivot = p->left;
	gp->left = pivot;
	p->left = pivot->right;
	pivot->right = p;
}

//rotates tree to left
//from given node
void Tree::lRotate(Node* gp, Node* p) {
	Node* pivot = p->right;
	gp->right = pivot;
	p->right = pivot->left;
	pivot->left = p;
}

//find balance factor of given node
int Tree::getBalance(Node* n) {
	if (n == NULL) {
		return 0;
	}
	else {
		int b = getHeight(n->left) - getHeight(n->right);
		return b;
	}
}
