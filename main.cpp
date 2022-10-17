#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "Person.h"
#include "Book.h"
using namespace std;

void ClearScreen() {
	cout << string(100, '\n');
};

class UserInterface{
	public:
		void Start(){
			//Simply starts the program (Could/should be changed to a do while loop)
			cout << "Would you like to test the Tree? (Y/N): ";

			//Runs a while loop that asks the user if they want to keep trying
			//different things every time they finish a function's goal
			string choice;
			cin >> choice;
			bool go = true;
			if ((choice == "Y") || (choice == "Yes") || (choice == "y") || (choice == "yes")) {

				//Initializes the Phone book
				Book MyBook;

				while (go) {
					//Prints out all of the options
					cout << "\nHere are the list of options:" << endl;
					cout << "\n1 - Add a person to the phonebook" << endl;
					cout << "2 - Find a number from a name" << endl;
					cout << "3 - Delete a person from the phonebook" << endl;
					cout << "4 - Change someone's number" << endl;
					cout << "5 - Display the entire phonebook" << endl;
					cout << "6 - Quit and save to file" << endl;
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
						double userNum;
						string userFirst, userLast;
						double output;
						int intOut;
						bool out;
						switch (num) {
							
						//Add()
						case 1:
							cout << "What is the first name? ";
							cin >> userFirst;
							cout << "\n";
							cout << "What is the last name? ";
							cin >> userLast;
							cout << "\n";
							cout << "What is the phone number? ";
							cin >> userNum;
							cout << "\n";
							MyBook.Add(userFirst, userLast, userNum);
							break;

						//Find()
						case 2:
							cout << "What is the first name? ";
							cin >> userFirst;
							cout << "\n";
							cout << "What is the last name? ";
							cin >> userLast;
							cout << "\n";
							output = MyBook.Find(userFirst, userLast);
							if (output == NULL) {
								cout << "That person was not found in your tree :(" << endl;
								break;
							}
							else {
								std::cout << std::fixed;
								std::cout << std::setprecision(0);
								cout << userFirst << " " << userLast << ": \n  -" << output << endl;
								break;
							}

						//Delete()
						case 3:
							cout << "First name to remove: ";
							cin >> userFirst;
							cout << "\n";
							cout << "Last name to remove: ";
							cin >> userLast;
							cout << "\n";
							MyBook.Delete(userFirst, userLast);
							break;

						//Change()
						case 4:
							MyBook.EmptyTree();
							cout << "The tree has been emptied!" << endl;
							break;

						//Display()
						case 5:
							if (MyBook.TreeSize() != 0) {
								cout << "Here is the entire phonebook: " << endl;
								MyBook.PrintTree();
								break;
							}
							else {
								cout << "There is currently nothing in the phonebook. \nPlease add some people to it first." << endl;
								break;
							}

						//Quit
						case 6:
							;
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
			return;
		}
};

int main() {
	UserInterface x;
	x.Start();

}