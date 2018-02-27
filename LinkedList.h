/****************************************************************************
Jody Bailey
CSC 306 - Operating Systems
11/09/2017
This is the header file.
****************************************************************************/
#pragma once

// Define a class list
class list
{
	// Private member variables
private:
	struct node
	{
		int value;
		int priority;
		node *next;
	};
	node *head;

	// Public member variables
public: 
	void insertHead(int);
	void insertTail(int);
	void insertSort(int);
	void initializeList();
	void insertPriority(int, int);
	void displayList();
	void deleteNode(int);
	void deleteList();
	void deleteTail();
	bool isEmpty();
	int output();
	int outputPriority();

	// Constructor
	list();

	// Destructor
	~list();
};