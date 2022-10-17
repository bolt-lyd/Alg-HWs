#include "Book.h"
#include <iostream>
#include <fstream>
using namespace std;

//default constructor
Book::Book() {
	root = NULL;
}

//destructor - empty all items from phonebook
Book::~Book() {
	EmptyBook();
}

//takes string, finds correct place, inserts it
void Book::Add(string fi, string l, double n) {
	//checks root value and sets x as root if none
	if (root == NULL) {
		root = new Person(fi, l, n);
	}
	//if root there, finds new place
	else {
		//find
		Person* temp = root;
		Person* gp = temp;
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
			temp->left = new Person(fi, l, n);
		}
		else {
			temp->right = new Person(fi, l, n);
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

//finds a person and returns their phone number
// returns empty string if not found
double Book::Find(string fi, string l) {
	Person* temp = root;
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

//returns number of people in phonebook
int Book::BookSize() {
	return NumNode;
}

//removes all nodes with no memory leaks
void Book::ClearBook(Person* t) {
	if (t == NULL) return;
	ClearBook(t->left);
	ClearBook(t->right);
	delete t;
}

void Book::EmptyBook() {
	ClearBook(root);
}

//removes given person from phonebook and returns it
void Book::Delete(string fi, string l) {

	Person* temp = root;
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
		Person* temp2 = temp->left;
		//two children
		if ((temp->left != NULL) && (temp->right != NULL)) {
			Person* t = temp2;
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
		Person* temp2 = temp->left;
		//two children
		if ((temp->left->left != NULL) && (temp->left->right != NULL)) {
			Person* t = temp2;
			Person* p = t;
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
		Person* temp2 = temp->right;
		//two children
		if ((temp->right->right != NULL) && (temp->right->left != NULL)) {
			Person* t = temp2;
			Person* p = t;
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

//prints the phonebook in alphabetical order
void Book::Print(Person* t) {
	if (t == NULL) return;
	Print(t->left);
	cout << t->first << " " << t->last << ": " << t->num << endl;
	Print(t->right);
}

void Book::Display() {
	Print(root);
}

//gets height of specific nodes of phonebook
int Book::getHeight(Person* temp) {
	if (temp == NULL) {
		return 0;
	}
	else {
		return temp->height;
	}
}

//Changes the number of a given person in the book
void Book::Change(string fi, string l, double n){
Person* temp = root;
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
		cout << "That person does not exist in the book. Please try again." << endl;
		return;
	}
	else {
		temp->num = n;
		cout << "The person: " << temp->first << " " << temp->last << "'s number has been changes to: " << temp->num << endl;
		return;
	}	
}

//max of two ints
int Book::max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

//rotates book to right 
//from given node
void Book::rRotate(Person* gp, Person* p) {
	Person* pivot = p->left;
	gp->left = pivot;
	p->left = pivot->right;
	pivot->right = p;
}

//rotates book to left
//from given node
void Book::lRotate(Person* gp, Person* p) {
	Person* pivot = p->right;
	gp->right = pivot;
	p->right = pivot->left;
	pivot->left = p;
}

//find balance factor of given node
int Book::getBalance(Person* n) {
	if (n == NULL) {
		return 0;
	}
	else {
		int b = getHeight(n->left) - getHeight(n->right);
		return b;
	}
}

//prints the phonebook in alphabetical order
void Book::PrintToFile(Person* t) {
	if (t == NULL) return;
	PrintToFile(t->left);
	ofstream myFile;
	myFile.open ("SaveBook.txt", ios::out | ios::app | ios::binary);
	myFile << t->first << " " << t->last << ": " << t->num << endl;
	myFile.close();
	PrintToFile(t->right);
}

/// Saves the tree to a txt file and then destroys the book
void Book::Quit(){
	ofstream myFile;
	myFile.open ("SaveBook.bin");
	myFile << "" << endl;
	myFile.close();
	PrintToFile(root);
	ClearBook(root);
}