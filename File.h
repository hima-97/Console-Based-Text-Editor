#pragma once
#include "Linkedlist.h"
#include <fstream>

class File : public Linkedlist
{
public:
	File() {}; // Default constructor

	// Class function to display the menu:
	void menu();

	// Function to load from a file:
	void loadFile();
};