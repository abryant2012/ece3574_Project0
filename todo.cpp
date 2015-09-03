#include "Todo.h"
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
using std::endl;
using std::cout;

void todo(istream& in, ostream& out)
{

	ToDoStruct *toDo; //initialize the array type
	toDo = new ToDoStruct[20]; //Array of initial size 10 made of of toDoStruct defined in header

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

		//test that fileName and command variables are correct 
		cout << "File:  " << fileName << endl;
		cout << "Command:  " << command << endl;


		/*
		If the command is add, then use load to save the information on an array, 
		add the new task as a toDoStruct to the end of the array, and save the file
		*/
		if (command == "add")
		{
			string description; 
			ToDoStruct addThis;

			int listSize = load(toDo, fileName);

			getline( in, description,'\n');

			cout << description << endl;

			toDo[listSize-1].completed = false;
			toDo[listSize-1].task = description;
			
			save(toDo, fileName, listSize);
		}

		//If the command is list, call list, which uses out
		if (command == "list")
		{
			list(fileName, out);
		}


		/*
		If the command is do, take in the int position of the task, 
		load the file into the array toDo, mark the task as completed, 
		and save the file 
		*/

		if (command == "do")
		{
			int listSize = load(toDo, fileName);

			int doThisTask;
			in >> doThisTask;
		
			toDo[doThisTask-1].completed = true;
			save(toDo, fileName, listSize - 1);
		}

		in >> start; // reprime
	}
}