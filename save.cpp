#include "Todo.h"
#include <iostream>
using std::string;
using std::ofstream;
using std::endl; 
using std::cout;

/*
//Takes an array of ToDoStructs, and saves them in a text file. 
Also Numbers the tasks and orders the tasks with incompleted tasks first.
*/
void save(ToDoStruct *&toDo, string fileName, int size)
{
	cout << "Saving " << endl;

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
			cout << "i am done " << endl;
			logging << count << ":[X]" << toDo[i].task << endl;
			count++;
		}
	}

	logging.close();
}