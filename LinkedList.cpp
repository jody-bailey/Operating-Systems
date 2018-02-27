/****************************************************************************
Jody Bailey
CSC 306 - Operating Systems
11/09/2017
This is the implementation file for LinkedList.h
****************************************************************************/
#include "LinkedList.h"
#include <iostream>

using namespace std;

// Constructor
list::list()
{
	head = new node;
	head->next = NULL;
}

// Function to initialize the queues
void list::initializeList()
{
	head = new node;
	head->next = NULL;
}

// Function used to insert a node in the front of the list
void list::insertHead(int num)
{
	node *newNode = new node;
	newNode->value = num;
	newNode->priority = NULL;

	// Check if head->next is null
	// If it is then the list is empty and just 
	// insert the node after head
	if (head == NULL)
	{
		head->next = newNode;
		newNode->next = NULL;
		return;
	}
	// Insert the node after head 
	else
	{
		newNode->next = head->next;
		head->next = newNode;
		return;
	}
}

// Function used to inset a node at the end of the list.
void list::insertTail(int num)
{
	node *newNode = new node;
	newNode->value = num;
	newNode->priority = NULL;
	node *temp = new node;
	temp = head;

	// Check if head->next is NULL and if it is
	// then insert the node after head
	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->next = NULL;
		return;
	}
	// Else, traverse to the end of the list and inset the node
	else
	{
		temp = temp->next;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = NULL;
		return;
	}
}

// Function used to inset a node in sorted order (largest at tail)
void list::insertSort(int num)
{
	node *newNode = new node;
	newNode->value = num;
	newNode->priority = NULL;

	// Check if head->next is NULL and if it is then
	// insert the node after head
	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->next = NULL;
		return;
	}
	// Else, traverse the list until the program finds a value
	// that is greater than or equal to the number passed in
	// and then inserts the node at that location
	else
	{
		node *temp = new node;
		temp = head;
		bool done = false;

		// Loop through the list
		while (done != true)
		{
			// If there is no node in the list then insert after head
			// and stop the loop
			if (temp->next == NULL)
			{
				temp->next = newNode;
				newNode->next = NULL;
				done = true;
				continue;
			}
			// If the next value in the list is less than the number passed
			// in then continue
			if (temp->next->value < num)
			{
				temp = temp->next;
				continue;
			}
			// If the next value is greater than or equal to the number
			// passed in then insert the node at that location and 
			// stop the loop
			else if (temp->next->value >= num)
			{
				newNode->next = temp->next;
				temp->next = newNode;
				done = true;
				continue;
			}
			// Else, continue
			else
			{
				temp = temp->next;
				continue;
			}
		}
		return;
	}
}

// Function used to insert nodes sorted by priority
void list::insertPriority(int num, int priority)
{
	node *newNode = new node;
	newNode->value = num;
	newNode->priority = priority;

	// Check if head->next is NULL and if it is then insert
	// the node after head
	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->next = NULL;
		return;
	}
	// Else, loop through the list and find the priority that is
	// less than or equal to the number passed in and insert node
	else
	{
		node *temp = new node;
		temp = head;
		bool done = false;

		// Loop through the list
		while (done != true)
		{
			// Check if the temp node points to null and if it does then
			// that means it is at the end of the list so just insert
			// the node after temp
			if (temp->next == NULL)
			{
				temp->next = newNode;
				newNode->next = NULL;
				done = true;
				continue;
			}
			// If the next nodes priority is greater than the one passed in 
			// then just continue
			if (temp->next->priority > priority)
			{
				temp = temp->next;
				continue;
			}
			// If the next nodes priority is less than or equal to 
			// the one passed in the insert the node at that 
			// location and stop the loop
			else if (temp->next->priority <= priority)
			{
				newNode->next = temp->next;
				temp->next = newNode;
				done = true;
				continue;
			}
			// Else, continue
			else
			{
				temp = temp->next;
				continue;
			}
		}
		return;
	}
}

// Function to delete the node matching the number passed in
void list::deleteNode(int num)
{
	node *current = new node;
	node *temp = new node;
	current = head;
	bool done = false;

	// Check if head points to null and if it does then
	// there are not any nodes in the list to delete
	if (head->next == NULL)
	{
		cout << "There are not any nodes in the list." << endl;
		return;
	}

	// Set temp
	temp = current->next;

	// Loop through the list untill the node is found that contains
	// the value passed in
	while (done != true)
	{
		// If the value is found then delete the node
		if (temp->value == num)
		{
			current->next = temp->next;
			delete temp;
			done = true;
			continue;
			return;
		}
		// If the end of the list is reached and the value was not found,
		// tell the user that the node was not found
		else if (temp->next == NULL)
		{
			cout << "The node with that value was not found." << endl;
			done = true;
			continue;
		}
		// Else, advance the position and continue
		else
		{
			current = temp;
			temp = current->next;
			continue;
		}
	}
	return;
}

// Function to delete the entire list.
void list::deleteList()
{
	node *current = new node;
	node *temp = new node;
	current = head;
	bool done = false;

	// Check if head points to null and if it does then
	// the list is empty
	if (head->next == NULL)
	{
		//cout << "There are not any nodes in the list to delete." << endl;
		return;
	}

	// Set temp
	temp = current->next;

	// Loop through the list
	while (done != true)
	{
		// Check if temp points to null and if it does then it is the last
		// node in the list so delete it and head and stop the loop
		if (temp->next == NULL)
		{
			delete temp;
			delete head;
			head = NULL;
			done = true;
			continue;
		}
		// Else, advance the position and continue
		else
		{
			current->next = temp->next;
			delete temp;
			temp = current->next;
			continue;
		}
	}
}

// Function to display the list
void list::displayList()
{
	node *current = new node;
	//node *temp = new node;

	current = head->next;
	//temp = current->next;
	bool done = false;

	// Make sure the list is not empty
	if (head->next == NULL)
	{
		cout << "There are not any nodes to print." << endl;
		return;
	}

	// Loop through the list to print it to the screen
	while (done != true)
	{
		if (current->next == NULL)
		{
			cout << current->value;
			if (current->priority != NULL)
			{
				cout << " " << current->priority << endl;
			}
			else
			{
				cout << endl;
			}
			
			done = true;
			continue;
		}
		else
		{
			cout << current->value;
			if (current->priority != NULL)
			{
				cout << " " << current->priority << endl;
			}
			else
			{
				cout << endl;
			}
			current = current->next;
		}
	}
	return;
}

// Function to delete only the tail of the list
void list::deleteTail()
{
	node *temp = new node;
	node *current = new node;
	temp = head;
	current = temp->next;

	if (head->next == NULL)
	{
		cout << "Cannot delete a tail that is not there." << endl;
		return;
	}
	else
	{
		bool done = false;

		while (done != true)
		{
			if (current->next == NULL)
			{
				delete current;
				temp->next = NULL;
				done = true;
				continue;
			}
			else
			{
				temp = current;
				current = current->next;
				continue;
			}
		}
	}

}

// Function to return if the queue is empty
bool list::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function that will return the data value stored in 
// the last element of the queue
int list::output()
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		node *current = new node;
		current = head->next;
		if (current->next == NULL)
		{
			return current->value;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			return current->value;
		}
	}
}

int list::outputPriority()
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		node *current = new node;
		current = head->next;
		if (current->next == NULL)
		{
			return current->priority;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			return current->priority;
		}
	}
}

// Destructor
list::~list()
{
	deleteList();
}