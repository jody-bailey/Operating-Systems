/****************************************************************************
Jody Bailey
CSC 306 - Operating Systems
11/09/2017
This program will create four data sets of random integers between 0-99 and
then another data set of random integers between 1-3 used for priority.
These data sets are then used to create queues of 10 members and then
members will be deleted and inserted to move them through the list until
the entire arrays have been processed.
****************************************************************************/
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	// Declare and open output file
	ofstream outFile("output.txt");

	// Declare all of the queues
	list fifoQ;
	list lifoQ;
	list sortedQ;
	list priorityQ;

	// Declare the needed arrays
	int fifo[100];
	int lifo[100];
	int sorted[100];
	int data[100];
	int priority[100];

	// Declare the input registers
	int inputOne = 0;
	int inputTwo = 0;
	int inputThree = 0;
	int inputFour = 0;
	int outputPriority = 0;

	// Declare the output registers
	int outputOne = 0;
	int outputTwo = 0;
	int outputThree = 0;
	int outputFour = 0;

	// Clockcycle variables
	int clockInOne = 0;
	int clockOutOne = 0;
	int clockInTwo = 0;
	int clockOutTwo = 0;
	int clockInThree = 0;
	int clockOutThree = 0;
	int clockInFour = 0;
	int clockOutFour = 0;

	srand(time(NULL));

	/************************************************************
	Run one - 1 register input and 1 register output
	************************************************************/

	// This for loop is used to populate the arrays with random integers 
	// to use for the data and priority.
	for (int i = 0; i < 100; i++)
	{
		fifo[i] = rand() % 100;
		lifo[i] = rand() % 100;
		sorted[i] = rand() % 100;
		data[i] = rand() % 100;
		priority[i] = rand() % 3 + 1;
	}

	cout << "Array values for run #1:" << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << "Array values for run #1:" << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// Print the arrays
	for (int i = 0; i < 100; i++)
	{
		cout << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t" 
			<< data[i] << "\t" << priority[i] << endl;
		outFile << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t" 
			<< data[i] << "\t" << priority[i] << endl;
	}

	cout << endl;
	cout << "----------------RUN ONE----------------" << endl << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << endl;
	outFile << "----------------RUN ONE----------------" << endl << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// This for loop is used to create the different queues needed with 10 members.
	for (int i = 0; i < 10; i++)
	{
		fifoQ.insertHead(fifo[i]);
		clockInOne++;
		lifoQ.insertTail(lifo[i]);
		clockInOne++;
		sortedQ.insertSort(sorted[i]);
		clockInOne++;
		priorityQ.insertPriority(data[i], priority[i]);
		clockInOne++;
	}

	for (int i = 10; i < 100; i++)
	{
		// FIFO
		inputOne = fifo[i];

		outputOne = fifoQ.output();
		clockOutOne++;

		fifoQ.deleteTail();
		fifoQ.insertHead(inputOne);
		clockInOne++;

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// LIFO
		inputOne = lifo[i];

		outputOne = lifoQ.output();
		clockOutOne++;

		lifoQ.deleteTail();
		lifoQ.insertTail(inputOne);
		clockInOne++;

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// SORTED
		inputOne = sorted[i];

		outputOne = sortedQ.output();
		clockOutOne++;

		sortedQ.deleteTail();
		sortedQ.insertSort(inputOne);
		clockInOne++;

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// PRIORITY
		inputOne = data[i];

		outputOne = priorityQ.output();
		outputTwo = priorityQ.outputPriority();
		clockOutOne++;

		priorityQ.deleteTail();
		priorityQ.insertPriority(inputOne, priority[i]);
		clockInOne++;
		
		cout << outputOne << "\t" << outputTwo << endl;
		outFile << outputOne << "\t" << outputTwo << endl;
	}

	// This for loop get the remaining 10 elements in the queue
	for (int i = 0; i < 10; i++)
	{
		// FIFO
		outputOne = fifoQ.output();
		clockOutOne++;

		fifoQ.deleteTail();

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// LIFO
		outputOne = lifoQ.output();
		clockOutOne++;

		lifoQ.deleteTail();

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// SORTED
		outputOne = sortedQ.output();
		clockOutOne++;

		sortedQ.deleteTail();

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// PRIORITY
		outputOne = priorityQ.output();
		outputTwo = priorityQ.outputPriority();
		clockOutOne++;

		priorityQ.deleteTail();

		cout << outputOne << "\t" << outputTwo << endl;
		outFile << outputOne << "\t" << outputTwo << endl;
	}

	/************************************************************
	Run two - 4 register input and 4 register output
	************************************************************/

	// Re-initialize the queues
	fifoQ.initializeList();
	lifoQ.initializeList();
	sortedQ.initializeList();
	priorityQ.initializeList();

	// Populate the arrays with new values
	for (int i = 0; i < 100; i++)
	{
		fifo[i] = rand() % 100;
		lifo[i] = rand() % 100;
		sorted[i] = rand() % 100;
		data[i] = rand() % 100;
		priority[i] = rand() % 3 + 1;
	}

	cout << endl;
	cout << "Array values for run #2:" << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << endl;
	outFile << "Array values for run #2:" << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// Print the arrays
	for (int i = 0; i < 100; i++)
	{
		cout << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t" 
			<< data[i] << "\t" << priority[i] << endl;
		outFile << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t" 
			<< data[i] << "\t" << priority[i] << endl;
	}

	// Insert the first 10 elements in the queues
	for (int i = 0; i < 10; i++)
	{
		fifoQ.insertHead(fifo[i]);
		lifoQ.insertTail(lifo[i]);
		sortedQ.insertSort(sorted[i]);
		priorityQ.insertPriority(data[i], priority[i]);
		clockInTwo++;
	}

	// Display all of the queues for debugging
	cout << endl;
	cout << "----------------RUN TWO----------------" << endl << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << endl;
	outFile << "----------------RUN TWO----------------" << endl << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// This for loop performs the similation of the registers
	for (int i = 10; i < 100; i++)
	{
		inputOne = fifo[i];
		inputTwo = lifo[i];
		inputThree = sorted[i];
		inputFour = data[i];

		outputOne = fifoQ.output();
		outputTwo = lifoQ.output();
		outputThree = sortedQ.output();
		outputFour = priorityQ.output();
		outputPriority = priorityQ.outputPriority();
		clockOutTwo++;

		fifoQ.deleteTail();
		lifoQ.deleteTail();
		sortedQ.deleteTail();
		priorityQ.deleteTail();

		fifoQ.insertHead(inputOne);
		lifoQ.insertTail(inputTwo);
		sortedQ.insertSort(inputThree);
		priorityQ.insertPriority(inputFour, priority[i]);
		clockInTwo++;

		// Output the data
		cout << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t" 
			<< outputFour << "\t" << outputPriority << endl;
		outFile << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t" 
			<< outputFour << "\t" << outputPriority << endl;
	}

	// This for loop gets the remaining data stored in the queues
	for (int i = 0; i < 10; i++)
	{
		outputOne = fifoQ.output();
		outputTwo = lifoQ.output();
		outputThree = sortedQ.output();
		outputFour = priorityQ.output();
		clockOutTwo++;

		fifoQ.deleteTail();
		lifoQ.deleteTail();
		sortedQ.deleteTail();
		priorityQ.deleteTail();

		// Output the data
		cout << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t" 
			<< outputFour << "\t" << outputPriority << endl;
		outFile << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t" 
			<< outputFour << "\t" << outputPriority << endl;
	}

	/*********************************************************************
	Run Three - Extra Credit
	1 register input and 4 register output
	*********************************************************************/

	// Re-initialize the queues
	fifoQ.initializeList();
	lifoQ.initializeList();
	sortedQ.initializeList();
	priorityQ.initializeList();

	// This for loop is used to populate the arrays with random integers 
	// to use for the data and priority.
	for (int i = 0; i < 100; i++)
	{
		fifo[i] = rand() % 100;
		lifo[i] = rand() % 100;
		sorted[i] = rand() % 100;
		data[i] = rand() % 100;
		priority[i] = rand() % 3 + 1;
	}

	cout << endl;
	cout << "Array values for run #3:" << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << "Array values for run #3:" << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// Print the arrays
	for (int i = 0; i < 100; i++)
	{
		cout << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t"
			<< data[i] << "\t" << priority[i] << endl;
		outFile << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t"
			<< data[i] << "\t" << priority[i] << endl;
	}

	cout << endl;
	cout << "----------------RUN THREE----------------" << endl << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << endl;
	outFile << "----------------RUN THREE----------------" << endl << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// This for loop is used to create the different queues needed with 10 members.
	for (int i = 0; i < 10; i++)
	{
		fifoQ.insertHead(fifo[i]);
		clockInThree++;
		lifoQ.insertTail(lifo[i]);
		clockInThree++;
		sortedQ.insertSort(sorted[i]);
		clockInThree++;
		priorityQ.insertPriority(data[i], priority[i]);
		clockInThree++;
	}

	// This for loop performs the similation of the registers
	for (int i = 10; i < 100; i++)
	{
		inputOne = fifo[i];
		inputTwo = lifo[i];
		inputThree = sorted[i];
		inputFour = data[i];

		outputOne = fifoQ.output();
		outputTwo = lifoQ.output();
		outputThree = sortedQ.output();
		outputFour = priorityQ.output();
		outputPriority = priorityQ.outputPriority();
		clockOutThree++;

		fifoQ.deleteTail();
		lifoQ.deleteTail();
		sortedQ.deleteTail();
		priorityQ.deleteTail();

		fifoQ.insertHead(inputOne);
		clockInThree++;
		lifoQ.insertTail(inputTwo);
		clockInThree++;
		sortedQ.insertSort(inputThree);
		clockInThree++;
		priorityQ.insertPriority(inputFour, priority[i]);
		clockInThree++;

		// Output the data
		cout << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t"
			<< outputFour << "\t" << outputPriority << endl;
		outFile << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t"
			<< outputFour << "\t" << outputPriority << endl;
	}

	// This for loop gets the remaining data stored in the queues
	for (int i = 0; i < 10; i++)
	{
		outputOne = fifoQ.output();
		outputTwo = lifoQ.output();
		outputThree = sortedQ.output();
		outputFour = priorityQ.output();
		clockOutThree++;

		fifoQ.deleteTail();
		lifoQ.deleteTail();
		sortedQ.deleteTail();
		priorityQ.deleteTail();

		// Output the data
		cout << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t"
			<< outputFour << "\t" << outputPriority << endl;
		outFile << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t"
			<< outputFour << "\t" << outputPriority << endl;
	}

	/*******************************************************************
	Run Four - Extra Credit
	4 register input and 1 register output
	*******************************************************************/

	// Re-initialize the queues
	fifoQ.initializeList();
	lifoQ.initializeList();
	sortedQ.initializeList();
	priorityQ.initializeList();

	// Populate the arrays with new values
	for (int i = 0; i < 100; i++)
	{
		fifo[i] = rand() % 100;
		lifo[i] = rand() % 100;
		sorted[i] = rand() % 100;
		data[i] = rand() % 100;
		priority[i] = rand() % 3 + 1;
	}

	cout << endl;
	cout << "Array values for run #4:" << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << endl;
	outFile << "Array values for run #4:" << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// Print the arrays
	for (int i = 0; i < 100; i++)
	{
		cout << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t"
			<< data[i] << "\t" << priority[i] << endl;
		outFile << fifo[i] << "\t" << lifo[i] << "\t" << sorted[i] << "\t"
			<< data[i] << "\t" << priority[i] << endl;
	}

	// Insert the first 10 elements in the queues
	for (int i = 0; i < 10; i++)
	{
		fifoQ.insertHead(fifo[i]);
		lifoQ.insertTail(lifo[i]);
		sortedQ.insertSort(sorted[i]);
		priorityQ.insertPriority(data[i], priority[i]);
		clockInFour++;
	}

	// Display all of the queues for debugging
	cout << endl;
	cout << "----------------RUN FOUR----------------" << endl << endl;
	cout << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	outFile << endl;
	outFile << "----------------RUN FOUR----------------" << endl << endl;
	outFile << "FIFO\tLIFO\tSorted\tData\tPriority" << endl;

	// This for loop performs the similation of the registers
	for (int i = 10; i < 100; i++)
	{
		inputOne = fifo[i];
		inputTwo = lifo[i];
		inputThree = sorted[i];
		inputFour = data[i];

		outputOne = fifoQ.output();
		clockOutFour++;
		outputTwo = lifoQ.output();
		clockOutFour++;
		outputThree = sortedQ.output();
		clockOutFour++;
		outputFour = priorityQ.output();
		clockOutFour++;
		outputPriority = priorityQ.outputPriority();

		fifoQ.deleteTail();
		lifoQ.deleteTail();
		sortedQ.deleteTail();
		priorityQ.deleteTail();

		fifoQ.insertHead(inputOne);
		lifoQ.insertTail(inputTwo);
		sortedQ.insertSort(inputThree);
		priorityQ.insertPriority(inputFour, priority[i]);
		clockInFour++;

		// Output the data
		cout << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t"
			<< outputFour << "\t" << outputPriority << endl;
		outFile << outputOne << "\t" << outputTwo << "\t" << outputThree << "\t"
			<< outputFour << "\t" << outputPriority << endl;
	}

	// This for loop get the remaining 10 elements in the queue
	for (int i = 0; i < 10; i++)
	{
		// FIFO
		outputOne = fifoQ.output();
		clockOutFour++;

		fifoQ.deleteTail();

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// LIFO
		outputOne = lifoQ.output();
		clockOutFour++;

		lifoQ.deleteTail();

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// SORTED
		outputOne = sortedQ.output();
		clockOutFour++;

		sortedQ.deleteTail();

		cout << outputOne << "\t";
		outFile << outputOne << "\t";

		// PRIORITY
		outputOne = priorityQ.output();
		outputTwo = priorityQ.outputPriority();
		clockOutFour++;

		priorityQ.deleteTail();

		cout << outputOne << "\t" << outputTwo << endl;
		outFile << outputOne << "\t" << outputTwo << endl;
	}

	// Display the clock cycles
	cout << endl;
	cout << "Clock cycles format: input - output" << endl;
	cout << "Clock cycles for first run: " << clockInOne << " - " 
		<< clockOutOne << endl;
	cout << "Clock cycles for second run: " << clockInTwo << " - " 
		<< clockOutTwo << endl;
	cout << "Clock cycles for third run: " << clockInThree << " - "
		<< clockOutThree << endl;
	cout << "Clock cycles for fourth run: " << clockInFour << " - "
		<< clockOutFour << endl << endl;

	outFile << endl;
	outFile << "Clock cycles for first run: " << clockInOne << " - " 
		<< clockOutOne << endl;
	outFile << "Clock cycles for second run: " << clockInTwo << " - " 
		<< clockOutTwo << endl;
	outFile << "Clock cycles for third run: " << clockInThree << " - "
		<< clockOutThree << endl;
	outFile << "Clock cycles for fourth run: " << clockInFour << " - "
		<< clockOutFour << endl << endl;

	cout << "Press ENTER to exit..." << endl;

	outFile.close();

	cin.get();
    return 0;
}