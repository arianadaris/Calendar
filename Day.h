#pragma once
#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include "Reminder.h"

using std::string;
using std::vector;

class Day
{
	private:
		int num;
		string day;
		vector<Reminder*> errands;

	public:
		Day();
		Day(int, string);

	// Methods
		void addReminder(string); // add reminder
		void addAppointment(string, string, string, string, string); // add appointment
		
		void removeErrand(int); // remove an errand, string descr
		Reminder* getErrand(int); // get an errand
		int getDayNum();
		string getDayName();
		int getNumErrand(); // get number of errands
		string toString();
};
#endif