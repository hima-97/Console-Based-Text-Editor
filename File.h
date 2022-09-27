#pragma once
#include "Linkedlist.h"

class File : public Linkedlist
{
public:
	// Default constructor:
	File() {}; 

	// Function to display the menu:
	void menu();

	// Function to load from a file:
	void loadFile();
};