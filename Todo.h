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
	bool completed = false;

	//String describing the task 
	string task = "";
};

#endif

//todo.cpp 
void todo(istream& in, ostream& out);

//list.cpp
void list(string fileName, ostream& out2);

//Takes a todo list in a txt file and saves each task to an array made up of ToDoStructs 
int load(ToDoStruct *&toDo, string file);

//Takes an array of ToDoStructs, and saves them in a text file. Also orders the tasks with incompleted tasks first. 
void save(ToDoStruct *&toDo, string fileName, int listSize);

void test_todo1();
void test_todo2();
void test_todo3();