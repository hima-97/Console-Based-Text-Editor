#include "File.h"

void File::menu()
{
	// This changes the color of the screen to aqua:
	system("color 3F");

	// This changes the color of the text to dark red:
	SetConsoleTextAttribute(hConsole, 52);
	goToxy(31, 6);
	printf("      Commands:       ");
	goToxy(31, 8);
	// This creates the menu bar:
	cout << char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220);

	// This changes the color of the text to black:
	SetConsoleTextAttribute(hConsole, 48);
	goToxy(31, 10);
	printf("1: New File ");
	goToxy(31, 11);
	printf("2: Load File ");
	goToxy(31, 12);
	printf("Esc: Exit/Save File ");

	// This changes the color of the text to dark red:
	SetConsoleTextAttribute(hConsole, 52);
	goToxy(31, 13);
	// This creates the menu bar:
	cout << char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< char(220) << char(220)
		<< endl;

	// This changes the color of the text to black:
	SetConsoleTextAttribute(hConsole, 48);
	goToxy(31, 16);
	int choice = 0;
	cin >> choice;

	// If "1" is pressed:
	if (choice == 1)
	{
		// This clears the screen:
		system("cls");
		// This changes the color of the screen back to black:
		system("color 0F");
		// Function to run the text editor:
		runEditor();
	}
	else if (choice == 2)
	{
		// This clears the screen:
		system("cls");
		// This changes the color of the screen back to black:
		system("color 0F");

		// Function to load a file into the text editor:
		loadFile();
	}
}

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