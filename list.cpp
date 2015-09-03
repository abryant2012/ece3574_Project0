#include "Todo.h"
#include <iostream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

/*
Takes the name of a txt file in as a string, goes line by line through the file, and 

Andrew Bryant - andrewpb@vt.edu - 9/2/15
*/
void list(string fileName, ostream& out2)
{
	int count; 
	count = 10; 
	string temp2;

	ifstream in2(fileName.c_str());
	getline(in2, temp2, '\n');

	while (!in2.fail())
	{
		//display each item in the to-do list, one by one
		if (temp2.empty())
			break;
		else 
			out2 << temp2 << endl;
		getline(in2, temp2, '\n');
	}
	in2.close();
}