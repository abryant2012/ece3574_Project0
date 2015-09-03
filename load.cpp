#include "Todo.h"
#include <iostream>
using std::string;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream; 
using std::endl;

/*
Load file for Project0

Takes in an array of toDoStructs and a file to load. Converts each task in the text file to 
a struct and adds it to the array. 

Andrew Bryant - andrewpb@vt.edu - 9/2/15
*/
int load(ToDoStruct *&toDo, string file)
{
	//open input file stream 
	ifstream fileIn(file); //////possibly remove in req

	if (!fileIn) 
		cout << "File In error" << endl;

	//create a temporary string to sace [ ] for incompleted tasks and [X] for completed tasks 
	string tempString;
	//create a temporary todo struct to add to the array
	ToDoStruct tempStruct;

	//initialize a count 
	int count = 0;

	//ignore the numbering 
	fileIn.ignore(4, ':');

	//Use getline to save the task from the file till it hits a new line 
	getline(fileIn, tempString, '\n');

	//loop until the end of the file is reached 
	while (!fileIn.fail())
	{

		//If the task is incomplete, set the value false 
		if (tempString.substr(0, 3) == "[ ]" )
			tempStruct.completed = false;
		else
		{
			//if the task is complete, set the value true 
			if (tempString.substr(0, 3) == "[X]" | tempString.substr(0, 3) == "[x]")
				tempStruct.completed = true;
		}

		tempStruct.task = tempString.substr(3, 400);
			
		//set the next value of the array to the temp. struct 
		toDo[count] = tempStruct;

		count++;

		//Repreime the tempStruct.task and doneString values 
		fileIn.ignore(4, ':');
		getline(fileIn, tempString, '\n');
	}

	//Close the input file
	fileIn.close();

	//Return the size of the array 
	return (count + 1);
}