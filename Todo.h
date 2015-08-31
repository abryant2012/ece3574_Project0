#include<iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::endl;
using std::cout;

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