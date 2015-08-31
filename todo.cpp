#include "Todo.h"
#include <iostream>

void todo(istream& in, ostream& out)
{
	ToDoStruct *toDo; //initialize the array type

	int size = 10; //Initial size is 10

	int count = 0; //Count, for now it is zero

	ofstream myLogging;

	toDo = new ToDoStruct[size]; //Array of initial size 10 made of of toDoStruct defined in header

	string command; //string variable for command to be read into 

	in >> command; //sets first word from user input as the command before entering while loop

	//continue while input does not fail 
	while (!in.fail())
	{

	}
}