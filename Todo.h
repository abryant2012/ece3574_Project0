#include<iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
//come back and move these
using std::string;
using std::istream;
using std::ostream;

#ifndef STRUCT_H
#define STRUCT_H


//Struct for each to-do task on the list 
struct ToDoStruct
{
	//boolean of whether the task has been completed or not
	bool completed;

	//String describing the task 
	string task;
};

#endif

//todo.cpp 
void todo(istream& in, ostream& out);

//list.cpp
void list(string fileName, ostream& out2);


int load(ToDoStruct *&toDo, string file);

void save(ToDoStruct toDo, string fileName);