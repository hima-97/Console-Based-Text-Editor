#include <iostream>
#include "Linkedlist.h"
#include "File.h"

void main()
{
	//char c;
	Linkedlist L; // Object of the "Linkedlist" class
	File F; // Object of the "File" class

	F.menu(); // This calls the menu function

	// This clears the screen once the user exit the program:
	system("cls");
	cout << "You have exit the text editor:" << endl;
	cout << "Your file has been saved under 'Output.txt' in C:\\temp\\Output.txt" << endl << endl;
}