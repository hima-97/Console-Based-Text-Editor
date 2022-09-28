#include "File.h"

void File::menu()
{
	printf("   CONSOLE-BASED TEXT EDITOR:       ");
	// This creates the menu bar:
	cout << "\n--------------------------------" << endl;

	printf("\n1: New File ");
	printf("\n2: Load File ");
	printf("\n3: Exit");
	printf("\n\nNote: Press ESC key twice at any time to close the editor and save your work");
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
		// To exit:
		default:
		{
			// This clears the screen once the user exit the program:
			system("cls");
			cout << "Thank you for using The Console-Based Text Editor\n";
			cout << "Your work has been saved in the 'MyText.txt' file, Goodbye!\n\n\n\n" << endl;
		}
	}
}