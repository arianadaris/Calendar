#include "Day.h"
#include "Reminder.h"
#include "Appointment.h"

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::to_string;
using std::vector;

Day::Day()
{
	this->num = 1;
	this->day = "Monday";
}

Day::Day(int num, string day)
{
	this->num = num;
	this->day = day;
}

void Day::addReminder(string descr)
{
	Reminder* reminder = new Reminder(descr);
	errands.push_back(reminder);
}

void Day::addAppointment(string descr, string startHr, string startMin, string endHr, string endMin)
{
	Appointment* appointment = new Appointment(descr, startHr, startMin, endHr, endMin);
	errands.push_back(appointment);
}

void Day::removeErrand(int index)
{
	index--;
	errands.erase(errands.begin() + index);
}

Reminder* Day::getErrand(int index)
{
	return errands[index - 1];
}

int Day::getDayNum()
{
	return this->num;
}

string Day::getDayName()
{
	return this->day;
}

int Day::getNumErrand()
{
	return errands.size();
}

string Day::toString()
{
	string str = to_string(this->num) + " - " + this->day + ": ";
	if (errands.size() > 0)
	{
		for (int i = 1; i < errands.size()+1; i++)
		{
			str = str + "\n\t" + getErrand(i)->toString();
		}
	}
	else
	{
		str = str + "No errands";
	}
	return str;
}