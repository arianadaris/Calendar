#include "Reminder.h"

#include <string>

Reminder::Reminder()
{
	this->descr = "Reminder";
}

Reminder::Reminder(string descr)
{
	this->descr = descr;
}

string Reminder::getDescr()
{
	return this->descr;
}

void Reminder::setDescr(string descr)
{
	this->descr = descr;
}

string Reminder::toString()
{
	string reminder = "Reminder - " + getDescr();
	
	return reminder;
}