#include "Calendar.h"
#include "Day.h"

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::ofstream;

// Methods
Calendar::Calendar()
{
	this->title = "Calendar";
	this->num = 30;
	this->start = 1;

	// Create Day** array
	this->days = new Day* [num];
	for (int i = 0; i < num; i++)
	{
		days[i] = new Day[1];
	}

	// Fill Day** array
	const char* nameOfDay[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	int i = 0;
	while (i < num)
	{
		days[i][0] = Day((i + 1), nameOfDay[i % 7]);
		i++;
	}
}

Calendar::Calendar(string title, int num, int start)
{
	this->title = title;
	this->num = num;
	this->start = start;

	// Create Day** array
	this->days = new Day* [num];
	for (int i = 0; i < num; i++)
	{
		days[i] = new Day[1];
	}

	// Fill Day** array
	const char* nameOfDay[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	int i = 1;
	while (i <= num)
	{
		// Get the correct index for the name of the day
		int index = (start % 7) - 1;
		if (index == -1)
			index = 6;
		else if (index == -2)
			index = 0;

		days[i-1][0] = Day((i), nameOfDay[index]);
		start++; // increment start to get following days
		i++;
	}
}

Calendar::~Calendar()
{
	delete[] this->days;
}

Day* Calendar::getDay(int num)
{
	return days[num - 1];
}

void Calendar::display()
{
	cout << "Calendar: " << this->title << endl;
	int i = 0;
	while (i < num)
	{
		string numErrands = to_string(days[i]->getNumErrand()); // get number of errands on that day

		// Formats proper phrasing: "errand"/"errands", if no errands, print "No" errands
		string word = "errands";
		if (numErrands == "0")
			numErrands = "No";
		else if (numErrands == "1")
			word = "errand";
		
		cout << to_string(days[i]->getDayNum()) << " - " << days[i]->getDayName() << ": " << numErrands << " " << word << endl;
		i++;
	}
}

void Calendar::saveToFile(string filename)
{
	ofstream saveFile;
	saveFile.open(filename + ".txt");
	saveFile << "Calendar: " << this->title << "\n---------------" << endl;

	for (int i = 1; i <= this->num; i++)
	{
		saveFile << getDay(i)->toString() << endl;
		saveFile << endl;
	}
	saveFile.close();
}