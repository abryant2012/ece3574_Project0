#include "Todo.h"
#include <iostream>
using std::string;
using std::ofstream;
using std::endl; 

/*
Save file for Project0

Takes an array of ToDoStructs, and saves them in a text file.
Also Numbers the tasks and orders the tasks with incompleted tasks first.

Andrew Bryant - andrewpb@vt.edu - 9/2/15
*/
void save(ToDoStruct *&toDo, string fileName, int size)
{

	ofstream logging; 
	logging.open(fileName.c_str()); //////////////possibly remove out req

	int count = 1;

	//First goes through the array of ToDoStructs and looks for incomplete tasks 
	for (int i = 0; i < size; i++) 
	{
		string tempString;
		if (toDo[i].completed == false)
		{
			logging << count << ":[ ]" << toDo[i].task << endl;
			count++;
		}
	}

	//Now goes through the array of ToDoStructs and looks for completed tasks
	for (int i = 0; i < size; i++)
	{
		string tempString;
		if (toDo[i].completed == true)
		{
			logging << count << ":[X]" << toDo[i].task << endl;
			count++;
		}
	}

	logging.close();
}