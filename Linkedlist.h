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
		Node* next; // Pointer of type "Node" and named "next"
		Node* prev; // Pointer of type "Node" and named "prev"
		// Default constructor:
		Node() { next = nullptr; prev = nullptr; letter = ' '; }
		// Parametrized constructor:
		Node(char c) { next = nullptr; prev = nullptr; letter = c; }
	};

	// Pointer of type "Node" and named "start" to track the beginning of a line:
	Node* start = nullptr;
	// Pointer of type "Node" and named "current" to track current position in linkedlist (i.e. cursor position):
	Node* current = nullptr;
	// Pointer of type "Node" and named "end" to track the end of a line:
	Node* end = nullptr;

	// X,Y coordinates for current position (i.e. cursor position):
	int x = 0, y = 0;

	// Input key:
	char inputKey;

	// Array pointer of type "Node" to track the lines in the text editor:
	// Note: text editor supports only 500 lines max.
	Node* rows[500];

	// Function to set the position of the cursor (note: #include <windows.h> to make it work):
	void goToxy(int x, int y);

	// Function to run the text editor:
	void runEditor();

	// Function to move cursor to the left:
	bool moveLeft();

	// Function to move cursor to the right:
	bool moveRight();

	// Function to move the cursor up:
	bool moveUp();

	// Function to move the cursor down:
	bool moveDown();

	// Function to insert a new node (i.e. letter) in the Linked list:
	void insertNode(char letter);

	// Function to delete a node (i.e. letter) in the Linked list:
	void deleteNode();

	// Function to insert a new row/line of nodes (i.e. letters):
	void addRow();

	// Function to print the linked list (i.e. text):
	void printList();

	// Function to save the linkedlist (i.e. text) into a file:
	void saveFile();
};