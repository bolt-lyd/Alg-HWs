#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "Node.h"
#include "Tree.h"
using namespace std;

void ClearScreen() {
	cout << string(100, '\n');
}


int main() {
	//Simply starts the program (Could/should be changed to a do while loop)
	cout << "Would you like to test the Tree? (Y/N): ";

	//Runs a while loop that asks the user if they want to keep trying
	//different things every time they finish a function's goal
	string choice;
	cin >> choice;
	bool go = true;
	if ((choice == "Y") || (choice == "Yes") || (choice == "y") || (choice == "yes")) {

		//Initializes the tree
		Tree myTree;

		while (go) {
			//Prints out all of the options
			cout << "\nHere are the list of options:" << endl;
			cout << "\n1 - Insert a int to the tree" << endl;
			cout << "2 - Find a number from a name" << endl;
			cout << "3 - Get the size of the tree" << endl;
			cout << "4 - Empty the entire tree" << endl;
			cout << "5 - Remove a given int from the tree" << endl;
			cout << "6 - Print the entire tree" << endl;
			cout << "\nWhich option would you like to choose?(Please enter only a number) " << endl;

			//Gets the users choice in char and converts to num,
			// then converts to correct num from ACSII num
			char charNum;
			cin >> charNum;
			int num = (charNum - 48);

			//Takes in the user's choice, checks to ensure it is one of the numbers
			//	that are options, then converts to an int and runs the relevant function
			//	If they dont select one of the numbers, it starts the loop over
			if ((num < 1) || (num > 6)) {
				cout << "Please only enter a number between 1 and 6" << endl;
			}
			else {
				//Initializes all variables used in the cases instead of
				// creating differnt ones for each case
				int userNum;
                string userFirst, userLast;
				int output;
				int intOut;
				bool out;
				switch (num) {
					//Insert()
				case 1:
					cout << "What is the first name? ";
					cin >> userFirst;
					cout << "\n";
                    cout << "What is the last name? ";
					cin >> userLast;
					cout << "\n";
                    cout << "What is the number? ";
					cin >> userNum;
					cout << "\n";
					myTree.Insert(userFirst, userLast, userNum);
					break;

					//Find()
				case 2:
					cout << "What is the first name? ";
					cin >> userFirst;
					cout << "\n";
                    cout << "What is the last name? ";
					cin >> userLast;
					cout << "\n";
					output = myTree.FindNum(userFirst, userLast);
					if (output == NULL) {
						cout << "That string was not found in your tree :(" << endl;
						break;
					}
					else {
						cout << "The string: " << output << " was found in the tree!" << endl;
						break;
					}

					//Size()
				case 3:
					intOut = myTree.TreeSize();
					cout << "There are " << intOut << " items currently in the tree." << endl;
					break;
					cout << "There are " << intOut << " items currently in the tree." << endl;
					break;

					//EmptyTree()
				case 4:
					myTree.EmptyTree();
					cout << "The tree has been emptied!" << endl;
					break;

					//Remove()
				case 5:
					cout << "first name to remove: ";
					cin >> userFirst;
					cout << "\n";
                    cout << "last name to remove: ";
                    cin >> userLast;
                    cout << "\n";
					myTree.Remove(userFirst, userLast);
					break;

					//PrintTree
				case 6:
					if (myTree.TreeSize() != 0) {
						cout << "Here is the entire tree: " << endl;
						myTree.PrintTree();
						break;
					}
					else {
						cout << "There is currently nothing in the tree. \nPlease add items to it first." << endl;
						break;
					}
				}
			}
			cout << "Would you like to try another function?(Y/N) ";
			cin >> choice;
			if ((choice == "Y") || (choice == "Yes") || (choice == "y") || (choice == "yes")) {
				go = true;
				system("clear");
			}
			else {
				go = false;
			}
		}
	}

	cout << "Thank you for using our program. \n~Cameron and Lydia" << endl;;
	return 0;
}