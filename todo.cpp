#include "Todo.h"
#include <iostream>

void todo(istream& in, ostream& out)
{
	ToDoStruct *toDo; //initialize the array type
	ToDoStruct *doneToDo;//"	"

	int size = 10; //Initial size is 10

	int count = 0; //Count, for now it is zero

	ofstream myLogging;

	toDo = new ToDoStruct[size]; //Array of initial size 10 made of of toDoStruct defined in header
	doneToDo = new ToDoStruct[size]; //Todostruct array of size 10 of completed tasks 

	string start; //string variable for command to be read into 

	in >> start; //sets first word from user input as the command before entering while loop

	//continue while input does not fail 
	while (!in.fail())
	{
		//if the first word in the command is not todo, stop the program
		if (start != "todo")
			break;

		//Call the next word in the input temp until we know if it is a command or a file name 
		string temp;
		in >> temp;

		//create filename and command variables 
		string fileName;
		string command;

		//if the user specifies their own filename, open that txt file as ofstream, and get command 
		if (temp == "-f")
		{
			in >> fileName;
			myLogging.open(fileName.c_str());
			in >> command;
		}

		//If the user does not specify their own file, use standard file and set command string variable to the contents of the temp string variable 
		else
		{
			fileName = "todo.txt";
			myLogging.open(fileName.c_str());
			command = temp;
		}



		in >> start; // reprime
	}
}