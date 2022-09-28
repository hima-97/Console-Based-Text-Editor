#include "File.h"

void File::menu()
{
	printf("   CONSOLE-BASED TEXT EDITOR:       ");
	// This creates the menu bar:
	cout << "\n--------------------------------" << endl;

	printf("\n1: New File ");
	printf("\n2: Exit");
	printf("\n\nNote: Press ESC at any time to close the editor and save your work");
	printf("\n\nSelect an option: ");

	int choice = 0;
	cin >> choice;

	if (choice == 1)
	{
		// This clears the screen:
		system("cls");
		// Function to run the text editor:
		runEditor();
	}
	else
	{
		// This clears the screen once the user exit the program:
		system("cls");
		cout << "Thank you for using the Console-Based Text Editor, Goodbye\n\n\n\n\n";
	}
}