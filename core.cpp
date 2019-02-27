//
// Created by Nguyen Duc Dung on 2019-02-15.
//
// Name: Nguyen Xuan Vinh
// Date: 25/02/2019
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "core.h"
#include <string>
#include <sstream>


using namespace std;
/// Prototype declaration
// void Initialization();
// void Finalization();

// void LoadConfiguration();
// void LoadMenu();
// void DisplayMenu();
// void ProcessUserChoice();
///--------------------------------------------------------------------

bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
string hello[20];
string menu[10];
// TODO: add more global variables to complete tasks

 // contain welcome text


///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization() {

	//LoadConfiguration();
	LoadMenu();
	// TODO: write the code to initialize the program
	__coreInitialized = true;
	//__isExiting = true;
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
	// TODO: write the code to clean up when the program exits
}

void LoadConfiguration() {

	ifstream f;

	f.open("conf.json");
	char s[300];
	while (strcmp(s, "  \"WelcomeText\": {") != 0) {
		f.getline(s, 300);
	}

	int i = 0;

	while (1) {
		char c[300];
		f.getline(c, 300);
		if (strcmp(c, "  },") == 0) {
			break;
		}
		else {
			string token;
			token = strtok(c, ":");

			token = strtok(NULL, "");

			token.erase(0, 2);

			if (token[token.length() - 1] == ',') {
				token.erase(token.length() - 2, 2);
			}
			else {
				token.erase(token.length() - 1, 1);
			}
			hello[i] = token;
			cout << hello[i] << endl;
			i++;
		}
	}

	f.close();
	// TODO: write code to load data from the configuration file
}

void LoadMenu() {
	// TODO: write code to load menu from the configuration file
	ifstream f;

	f.open("conf.json");
	char s[300];
	while (strcmp(s, "  \"Menu\": {") != 0) {
		f.getline(s, 300);
	}

	int i = 0;

	while (1) {
		char c[300];
		f.getline(c, 300);
		if (strcmp(c, "  },") == 0) {
			break;
		}
		else {
			string token;
			token = strtok(c, ":");

			token = strtok(NULL, "");

			token.erase(0, 2);

			if (token[token.length() - 1] == ',') {
				token.erase(token.length() - 2, 2);
			}
			else {
				token.erase(token.length() - 1, 1);
			}

			menu[i] = token;
			//cout << menu[i] << endl;
			i++;
			//cout << menu[i].length() << endl;
		}
	}

	f.close();
}

void DisplayMenu() {
	// TODO: Display the menu loaded from configuration file
	int i = 0;
	while (menu[i].length() != 0) {
		cout << i + 1 << ". " << menu[i] << endl;
		i++;
	}
	__isExiting = true;
	cout << "Please select:" << endl;
}

void ProcessUserChoice() {
	// TODO: Read user input and process
	bool check = true; // check if invalid input
	
	string s;
	cin >> s;
	
	stringstream ss(s);
	ss >> __userChoice;
	
	bool isNumber = true;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			if (s[0] == '-' || s[0] == '+') {	
				if (s.length() == 1)
					isNumber = false;
			}
			else {
				if (isdigit(s[0]) == false)
					isNumber = false;
			}
		}else if (isdigit(s[i]) == false)
			isNumber = false;
	}
	if(isNumber == false){
	
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid input, please input an integer number." << endl;
		check = false;
	}
	else if (__userChoice < 1 || __userChoice >5) {
		cout << "Please select a number from 1 to 5." << endl;
		check = false;
	}
	else if(__userChoice !=5){
		
		cout << "You select menu item " << __userChoice << " Processing ...Done!" << endl;
		check = false;
	}
	else {
	}
	if (check == false) {
		DisplayMenu();
		ProcessUserChoice();
	}
}