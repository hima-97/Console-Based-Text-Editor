#include "Linkedlist.h"

// Function to set the position of the cursor:
void Linkedlist::goToxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to get a random number from 1 to 15:
int Linkedlist::randomColor()
{
	int i;

	i = (rand() % 15) + 1;

	if (i != 1)
	{
		return i;
	}
}

// Function to move cursor to the left:
bool Linkedlist::moveLeft()
{
	// As long as the screen does not end, the cursor can move to the left:
	if (x > 0)
	{
		x--; // Cursor moves to the left

		if (current->prev != nullptr)
		{
			current = current->prev; // "current" moves to the left (as long as the left/previous node is not empty)
		}
		else
		{
			current = start; // If "current" is at the beginning, then it means it's equal to "start"
		}
		return true;
	}
	else
		return false;
}

// Function to move cursor to the right:
bool Linkedlist::moveRight()
{
	if (current->next != nullptr)
	{
		x++; // Cursor moves to the right (as long as the right/next node is not empty)

		current = current->next; // "current" moves to the right (as long as the right/next node is not empty)
		return true;
	}
	else
		return false;
}

// Function to move the cursor up:
bool Linkedlist::moveUp()
{
	// As long as the screen does not end, the cursor can move up:
	if (y > 0)
	{
		y--; // Cursor moves up

		// This keeps track of the number of nodes (i.e. letters) in the linkedlist before "current":
		int counter = 0;
		Node* temp = start;
		while (temp != current)
		{
			temp = temp->next;
			counter++;
		}

		/*
		Once the cursor goes up, you need to start from the beginning of the line and move "current"
		as many times as the number of nodes counted (i.e. value of "counter") in the line below, using a new counter variable,
		unless there is	no node (i.e. letter) after "current" (Note: make also sure that the row/line above is not empty):
		*/
		x = 0;
		int counter2 = 0;
		start = rows[y];
		current = start;
		if (current == nullptr)
		{
			return true;
		}
		else
		{
			while (current->next != nullptr && counter2 != counter)
			{
				counter2++;
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
	// As long as there is a new row/line below, the cursor can move up:
	if (rows[y + 1] != nullptr)
	{
		y++; // Cursor moves down

		// This keeps track of the number of nodes (i.e. letters) in the linkedlist before "current":
		int counter = 0;
		Node* temp = start;
		while (temp != current)
		{
			temp = temp->next;
			counter++;
		}

		/*
		Once the cursor goes down, you need to start from the beginning of the line and move "current"
		as many times as the number of nodes counted (i.e. value of "counter") in the line above, using a new counter variable,
		unless there is	no node (i.e. letter) after "current":
		*/
		x = 0;
		int counter2 = 0;
		start = rows[y];
		current = start;
		while (current->next != nullptr && counter2 != counter)
		{
			counter2++;
			current = current->next;
			x++;
		}
		return true;
	}
	else
		return false;
}

// Function to run the text editor:
void Linkedlist::runEditor()
{
	while ((c = _getch()) != 27) // The loop will break once "esc" is pressed
	{
		if ((int)c == -32) // This is a flag checking if the user is pressing an arrow key (ascii = -32)
		{
			c = _getch(); // This reads the user input (note: #include <conio.h> to make it work)

			if ((int)c == 75) // Left arrow is pressed
			{
				moveLeft();
			}
			else if ((int)c == 77) // Right arrow is pressed
			{
				moveRight();
			}
			else if ((int)c == 72) // Up arrow is pressed
			{
				moveUp();
			}
			else if ((int)c == 80) // Down arrow is pressed
			{
				moveDown();
			}
		}
		else if (c == 8) // Backspace is pressed
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

		// Function to print the linked list:
		printList();
	}
	// Function to save into a file:
	saveFile();
}

// Function to insert a node in the Linked list:
void Linkedlist::insertNode(char letter)
{
	// Code to type and allocate the first character of the text editor:
	if (start == nullptr)
	{
		Node* temp = new Node(letter);
		start = temp;
		current = start;
		rows[y] = start;
		//x++; // Cursor moves to the right
	}
	// Code to type and allocate the rest of the charachters:
	else
	{
		// This changes the color of the text (random color):
		SetConsoleTextAttribute(hConsole, randomColor());

		Node* temp = new Node(letter); // Every time the user types a letter, a new "temp" pointer gets created, pointing to a new "Node" class

		// Code to type at the end of the linked list:
		if (current->next == nullptr)
		{
			current->next = temp;
			temp->prev = current;
			current = temp;
			x++; // Cursor moves to the right
		}
		// Code to type at the beginning of the linked list:
		else if (current == start)
		{
			temp->next = start;
			start->prev = temp;
			current = start;
			start = temp;
			rows[y] = start;
			x++; // Cursor moves to the right
		}
		// Code to type in between the linked list:
		else if (current->next != nullptr)
		{
			/*temp->next = current->next;
			current->next->prev = temp;
			temp->prev = current;
			current->next = temp;
			current = temp;*/
			x++; // Cursor moves to the right

			temp->next = current;
			temp->prev = current->prev;
			current->prev->next = temp;
			current->prev = temp;
			temp = current;
		}
	}
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
		rows[y] = start;
		current = start;
	}
	// This deletes a node at the beginning of the linked list:
	else if (current == start && current->next != nullptr)
	{
		temp = start;
		start = start->next;
		start->prev = temp;
		delete temp;
		rows[y] = start;
		current = start;
	}
	// This deletes a node at the end of the linked list:
	else if (current->next == nullptr)
	{
		current = current->prev;
		delete current->next;
		current->next = nullptr;
		x--; // Cursor moves to the left
	}
	// This deletes a node in between of the linked list:
	else
	{
		if (current->prev != start)
		{
			temp = current;
			current->prev->next = current->next;
			current->next->prev = current->prev;
			current = temp->prev;
			delete temp;
			x--;
		}
		else
		{
			temp = current;
			start->next = current->next;
			current->next->prev = start;
			current = start;
			delete temp;
			x = 0;
		}
	}
}

// Function to insert a new row/line:
void Linkedlist::addRow()
{
	y++; // Cursor moves down
	x = 0; // Cursor moves to far left
	start = nullptr;
	rows[y] = start;
	current = start;
}

// Function to print the linked list:
void Linkedlist::printList()
{
	// Every time you type, this will clear the screen and re-print everything:
	system("cls");
	goToxy(0, 0);

	Node* temp;

	// This loop will print everything until the array is empty (i.e. there are no more rows. Note: size of array is 20)
	for (int i = 0; i < 20; i++)
	{
		temp = rows[i];

		// This prints one linked list (i.e. one row)
		while (temp != nullptr)
		{
			cout << temp->letter;
			temp = temp->next;
		}
		cout << endl; // After a line is printed, it's time to start the next line 
	}
	goToxy(x, y);
}

void Linkedlist::saveFile()
{
	ofstream outfile; // Object of the class

	outfile.open("C:\\temp\\Output.txt"); // This opens the output file

	Node* temp;

	// This loop will print everything until the array is empty (i.e. there are no more rows. Note: size of array is 20)
	for (int i = 0; i < 20; i++)
	{
		temp = rows[i];

		// This prints one linked list (i.e. one row)
		while (temp != nullptr)
		{
			outfile << temp->letter;
			temp = temp->next;
		}
		outfile << endl; // After a line is printed, it's time to start the next line 
	}
	outfile.close(); // This closes the output file
}