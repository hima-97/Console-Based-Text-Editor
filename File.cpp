#include "File.h"

void File::menu()
{
	printf("   CONSOLE-BASED TEXT EDITOR:       ");
	// This creates the menu bar:
	cout << "\n--------------------------------" << endl;

	printf("\n1: New File ");
	printf("\n2: Load File ");
	printf("\n3: Exit");
	printf("\n\nSelect an option: ");

	int choice = 0;
	cin >> choice;

	switch (choice)
	{
		// For new file:
		case 1:
		{
			// This clears the screen:
			system("cls");
			// Function to run the text editor:
			runEditor();
		}
		// For uploading file:
		case 2:
		{
			// This clears the screen:
			system("cls");
			// Function to run the text editor:
			loadFile();
		}
		// To exit:
		default:
		{
			// This clears the screen once the user exit the program:
			system("cls");
			cout << "Thank you for using The Console-Based Text Editor, goodbye!\n\n\n\n" << endl;
		}
	}
}

// Function to load from a file:
void File::loadFile()
{
	ifstream infile;
	infile.open("C:\\temp\\input.txt");
	//char userInput;
	char c;

	while (infile.get(c))
	{
		if (c == 8) // Backspace is pressed
		{
			// Function to delete a node in the linked list:
			deleteNode();
		}
		else if (c == 13) // Enter is pressed
		{
			// Function to insert a new row/line:
			addRow();
		}
		else
		{
			// Function to insert a node in the linked list:
			insertNode(c);
		}
	}
	// Function to print the linked list:
	printList();

	// This returns the cursor at x-y position:
	goToxy(0, 0);

	// Function to run the text editor:
	runEditor();
}