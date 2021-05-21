#include "Appointment.h"

#include <string>

Appointment::Appointment()
{
	this->descr = "Appointment";
	this->startHr = "0";
	this->startMin = "0";
	this->endHr = "0";
	this->endMin = "0";
}
Appointment::Appointment(string descr, string startHr, string startMin, string endHr, string endMin)
{
	this->descr = descr;
	this->startHr = startHr;
	this->startMin = startMin;
	this->endHr = endHr;
	this->endMin = endMin;
}

string Appointment::getTime()
{
	string start = startHr + ":" + startMin;
	string end = endHr + ":" + endMin;
	string time = start + " - " + end;
	return time;
}

void Appointment::setTime(string startHr, string startMin, string endHr, string endMin)
{
	this->startHr = startHr;
	this->startMin = startMin;
	this->endHr = endHr;
	this->endMin = endMin;
}

string Appointment::toString()
{
	string appointment = "Appointment - " + this->getTime() + " - " + this->descr;
	return appointment;
}