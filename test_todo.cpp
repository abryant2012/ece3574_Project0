#include "Todo.h"
#include <assert.h>
#include<iostream>
using std::cout;
using std::endl;

/*
Test 1, creates a toDoStruct array, saves it, loads it, and makes sure the load
returned the correct size
*/
void test_todo1()
{
	ToDoStruct *toDoTest; //initialize the array type
	toDoTest = new ToDoStruct[5]; //Array of initial size 10 made of of toDoStruct defined in header
	toDoTest[0].completed = false;
	toDoTest[0].task = "Do your homework";
	toDoTest[1].completed = false;
	toDoTest[1].task = "Respond to email";
	toDoTest[2].completed = true;
	toDoTest[2].task = "Finish laundry";
	save(toDoTest, "testFile.txt", 3);
	int size = load(toDoTest, "testFile.txt");

	assert(size == 4);
	cout << "testing 1 passed" << endl;
}

/*
Test 2, creates a toDoStruct array, saves it, loads it, and assert that the array is in the 
correct order with the correct values 
*/
void test_todo2()
{
	ToDoStruct *toDoTest; //initialize the array type
	toDoTest = new ToDoStruct[5]; //Array of initial size 10 made of of toDoStruct defined in header
	toDoTest[0].completed = false;
	toDoTest[0].task = " Do your homework";
	toDoTest[1].completed = false;
	toDoTest[1].task = " Respond to email";
	toDoTest[2].completed = true;
	toDoTest[2].task = " Finish laundry";
	save(toDoTest, "testFile.txt", 3);
	int size = load(toDoTest, "testFile.txt");
	assert(toDoTest[2].completed == true);
	assert(toDoTest[0].task == " Do your homework");

	cout << "testing 2 passed" << endl;
}

/*
Test 3, creates a toDoStruct array with the first task being completed, saves it, loads it, 
and make sure that it gets moved to the bottom of the list. 
*/
void test_todo3()
{
	ToDoStruct *toDoTest; //initialize the array type
	toDoTest = new ToDoStruct[5]; //Array of initial size 10 made of of toDoStruct defined in header
	toDoTest[0].completed = true;
	toDoTest[0].task = " Do your homework";
	toDoTest[1].completed = false;
	toDoTest[1].task = " Respond to email";
	toDoTest[2].completed = false;
	toDoTest[2].task = " Finish laundry";
	save(toDoTest, "testFile.txt", 3);
	int size = load(toDoTest, "testFile.txt");
	assert(toDoTest[2].completed == true);
	assert(toDoTest[2].task == " Do your homework");
	assert(toDoTest[0].completed == false);
	assert(toDoTest[0].task == " Respond to email");

	cout << "testing 3 passed" << endl;
}