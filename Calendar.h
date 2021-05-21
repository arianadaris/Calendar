#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H

#include "Day.h"
#include <string>

using std::string;

class Calendar
{
	private:
		string title;
		int num, start;
		Day** days;

	public:
		Calendar();
		Calendar(string, int, int); // title, num, start
		~Calendar();

	// Methods
		Day* getDay(int); // get a single day's agenda
		void display(); // display calendar
		void saveToFile(string); // save calendar to a file, string filename
};
#endif