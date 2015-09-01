#include "Todo.h"
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;

void todo(istream& in, ostream& out)
{

	ToDoStruct *toDo; //initialize the array type
	int size = 10; //Initial size is 10
	toDo = new ToDoStruct[size]; //Array of initial size 10 made of of toDoStruct defined in header

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

		//if the user specifies their own filename, use that txt file as ofstream, and get command 
		if (temp == "-f")
		{
			in >> fileName;
			in >> command;
		}

		//If the user does not specify their own file, use standard file and set command string variable to the contents of the temp string variable 
		else
		{
			fileName = "todo.txt";
			command = temp;
		}

		if (command == "add")
		{
			string description; 
			ToDoStruct addThis;

			int listSize = load(toDo, fileName);

			getline( in, description,'\n');
			addThis.completed = false;
			addThis.task = description;

			toDo[listSize] = addThis;
			
			//save(toDo, fileName);
		}

		if (command == "list")
		{
			list(fileName, out);
		}

		if (command == "do")
		{
			int doThisTask;
			in >> doThisTask;
			int listSize = load(toDo, fileName);
			toDo[doThisTask].completed = true;
			//save(toDo, fileName);
			

		}

		in >> start; // reprime
	}
}