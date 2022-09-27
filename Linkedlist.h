#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>  // Used for random
#include <fstream> // Used for file manipulation
using namespace std;

class Linkedlist
{
public:
	// Class/Struct named "Node" that has different "fields" to hold data:
	struct Node
	{
		char letter;
		Node* next; // Pointer variable "next" of the class "Node"
		Node* prev; // Pointer variable "prev" of the class "Node"
		Node() { next = nullptr; prev = nullptr; letter = ' '; } // Default constructor that initializes "letter" and makes the pointers "next" and "prev" point
		// to nothing everytime an object of the "Node" class is created
		Node(char c) { next = nullptr; prev = nullptr; letter = c; } // Parametrized constructor that assigns "c" to "letter" and makes the pointers "next" and "prev" point
		// to nothing everytime an object of the "Node" class is created
	};

	Node* start = nullptr; // Creating and initializing a pointer named "start"
	Node* current = nullptr; // Creating and initializing a pointer named "current", which will move according to the cursor position
	int x = 0, y = 0; // X and Y coordinates for the cursor position
	char c;
	Node* rows[20]; // Array of pointers of the class "Node", used to write in multiple rows/lines

	// Function to set the position of the cursor (note: #include <windows.h> to make it work):
	void goToxy(int x, int y);

	// Use this line to be able to change the text color from now on:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Function to run the text editor:
	void runEditor();

	// Function to get a random number from 1 to 15:
	int randomColor();

	// Function to move cursor to the left:
	bool moveLeft();

	// Function to move cursor to the right:
	bool moveRight();

	// Function to move the cursor up:
	bool moveUp();

	// Function to move the cursor down:
	bool moveDown();

	// Function to insert a new node in the Linked list:
	void insertNode(char letter);

	// Function to delete a node in the Linked list:
	void deleteNode();

	// Function to insert a new row/line:
	void addRow();

	// Function to print the linked list:
	void printList();

	// Function to save into a file:
	void saveFile();
};