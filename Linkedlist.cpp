#include "Linkedlist.h"

// Function to set the position of the cursor:
void Linkedlist::goToxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to run the text editor:
void Linkedlist::runEditor()
{
	// Loop that executes until esc key is pressed:
	while ((inputKey = _getch()) != 27)
	{
		// Checking if an arrow key is pressed:
		if ((int)inputKey == -32)
		{
			inputKey = _getch(); // This reads the user input (note: #include <conio.h> to make it work)

			// Left arrow pressed:
			if ((int)inputKey == 75)
			{
				moveLeft();
			}
			// Right arrow pressed:
			else if ((int)inputKey == 77)
			{
				moveRight();
			}
			// Up arrow pressed:
			else if ((int)inputKey == 72)
			{
				moveUp();
			}
			// Down arrow pressed:
			else if ((int)inputKey == 80)
			{
				moveDown();
			}
		}
		// Backspace pressed:
		else if (inputKey == 8)
		{
			// Function to delete a node in the linked list:
			deleteNode();
		}
		// Enter pressed:
		else if (inputKey == 13)
		{
			// Function to insert a new row/line:
			addRow();
		}
		// Tab pressed:
		else if (inputKey == 9)
		{
			// Do nothing
		}
		else
		{
			// Function to insert a node in the linked list:
			insertNode(inputKey);
		}

		// Function to print the linked list:
		printList();
	}

	// Function to save text into a file:
	saveFile();
}

// Function to move cursor to the left:
bool Linkedlist::moveLeft()
{
	// If the screen does not end:
	if (x > 0)
	{
		// Cursor moves left:
		x--;

		// You are at the beginning of a line:
		if (x == 0 || x == 1)
			current = start;
		// If left/previous node is not empty, then it becomes the new "current":
		else if (current->prev != nullptr)
		{
			current = current->prev;
		}
		return true;
	}
	else
		return false;
}

// Function to move cursor to the right:
bool Linkedlist::moveRight()
{
	// If current and right/next node are not empty, then it becomes the new "current":
	if (current != nullptr && current->next != nullptr)
	{
		// Cursor moves right:
		x++;

		// If after moving to the right you are at x = 1 position, then it means the current node is still the start node:
		if (x == 1)
		{
			current = start;
		}
		// If right/next node is not empty, then it becomes the new "current":
		else
		{
			current = current->next;
		}
		return true;
	}
	else
		return false;
}

// Function to move the cursor up:
bool Linkedlist::moveUp()
{
	// If screen does not end:
	if (y > 0)
	{
		// Cursor moves up:
		y--; 

		// This keeps track of the number of nodes (i.e. letters) in the linkedlist before "current":
		int numberOfNodesBeforeCurrent = 0;
		Node* temp = start;
		while (temp != current)
		{
			temp = temp->next;
			numberOfNodesBeforeCurrent++;
		}

		/*
		When you move up, you need to count the numer of nodes before the cursor in the line you are moving from
		and leave the same amount of nodes in the new current line before placing the cursor back:
		*/
		int countNodes = 0;
		start = rows[y];
		current = start;
		x = 0; // Starting position for counting and finding final x position

		// Checking if line above is not empty:
		if (current == nullptr)
		{
			return true;
		}
		else
		{
			while (current->next != nullptr && countNodes != numberOfNodesBeforeCurrent)
			{
				countNodes++;
				current = current->next;
				x++;
			}
			return true;
		}
	}
	else
		return false;
}

// Function to move the cursor down:
bool Linkedlist::moveDown()
{
	// If there is a new row/line below:
	if (rows[y + 1] != nullptr)
	{
		// Cursor moves down:
		y++;

		// This keeps track of the number of nodes (i.e. letters) in the linkedlist before "current":
		int numberOfNodesBeforeCurrent = 0;
		Node* temp = start;
		while (temp != current)
		{
			temp = temp->next;
			numberOfNodesBeforeCurrent++;
		}

		/*
		When you move down, you need to count the numer of nodes before the cursor in the line you are moving from
		and leave the same amount of nodes in the new current line before placing the cursor back:
		*/
		int countNodes = 0;
		start = rows[y];
		current = start;
		x = 0; // Starting position for counting and finding final x position
		while (current->next != nullptr && countNodes != numberOfNodesBeforeCurrent)
		{
			countNodes++;
			current = current->next;
			x++;
		}
		return true;
	}
	else
		return false;
}

// Function to insert a node in the Linked list:
void Linkedlist::insertNode(char letter)
{
	// Every time the user presses a letter, a new "temp" pointer gets created pointing to a new "Node" with the letter in it:
	Node* temp = new Node(letter);

	// Code to type and allocate the first character of the text editor:
	if (start == nullptr)
	{
		start = temp;
		current = start;
		rows[y] = start;
	}
	// Code to type and allocate the rest of the charachters:
	else
	{
		// Code to type at the end of the linked list:
		if (current->next == nullptr)
		{
			current->next = temp;
			temp->prev = current;
			current = temp;
		}
		// Code to type in between the linked list:
		else if (current->next != nullptr && x != 0)
		{
			temp->prev = current;
			temp->next = current->next;
			current->next->prev = temp;
			current->next = temp;
			current = temp;
		}
		// Code to type at the beginning of the linked list:
		else if (current == start && x == 0)
		{
			temp->next = start;
			start->prev = temp;
			start = temp;
			current = start;
			rows[y] = start;
		}
	}
	// Cursor moves right:
	x++; 
}

// Function to delete a node in the Linked list:
void Linkedlist::deleteNode()
{
	// Temporary node:
	Node* temp = new Node();

	// This is for when there's an empty linked list:
	if (start == nullptr)
	{
		return;
	}
	// This deletes a node when it is the only node of the linked list:
	else if (current == start && current->next == nullptr)
	{
		delete start; // Note: you only deleted the location, but not the pointer (it can be re-used)
		start = nullptr;
		current = start;
		rows[y] = start;
		x = 0;
	}
	// This deletes a node at the beginning of the linked list:
	else if (current == start && current->next != nullptr)
	{
		if (x != 0)
		{
			temp = start;
			start = start->next;
			delete temp;
			current = start;
			rows[y] = start;
			x--;
		}
		else
			return;
	}
	// This deletes a node at the end of the linked list:
	else if (current->next == nullptr)
	{
		temp = current;
		current = current->prev;
		current->next = nullptr;
		delete temp;
		x--;
	}
	// This deletes a node in between of the linked list:
	else
	{
		temp = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = current->prev;
		delete temp;
		x--;
	}
}

// Function to insert a new row/line:
void Linkedlist::addRow()
{
	y++; // Cursor moves down
	x = 0; // Cursor moves to far left
	start = nullptr;
	current = start;
	rows[y] = start;
}

// Function to print the linked list:
void Linkedlist::printList()
{
	// Every time you type, this will clear the screen and re-print everything:
	system("cls");
	goToxy(0, 0);

	Node* temp;

	// This loop will print everything until the array is empty (i.e. there are no more rows/lines):
	// Note: text editor supports only 20 lines
	for (int i = 0; i < 20; i++)
	{
		temp = rows[i];

		// This prints one linked list (i.e. one row/line)
		while (temp != nullptr)
		{
			cout << temp->letter;
			temp = temp->next;
		}
		// Start new line to print next incoming line:
		cout << endl;
	}
	goToxy(x, y);
}

void Linkedlist::saveFile()
{
	// Object to write to external file:
	ofstream outfile("MyText.txt");

	Node* temp;

	// This loop will print everything until the array is empty (i.e. there are no more rows/lines):
	// Note: text editor supports only 20 lines
	for (int i = 0; i < 20; i++)
	{
		temp = rows[i];

		// This prints one linked list (i.e. one row/line)
		while (temp != nullptr)
		{
			outfile << temp->letter;
			temp = temp->next;
		}
		// Start new line to print next incoming line:
		outfile << endl;
	}
	outfile.close();
}