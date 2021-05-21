#pragma once
#ifndef REMINDER_H
#define REMINDER_H

#include <string>

using std::string;

class Reminder
{
	private:
		string descr;

	public:
		Reminder();
		Reminder(string);

	// Methods
		string getDescr(); // get Reminder description
		void setDescr(string); // set Reminder description, string descr
		virtual string toString();
};
#endif