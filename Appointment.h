#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Reminder.h"

class Appointment: public virtual Reminder
{
	private:
		string startHr, startMin, endHr, endMin, descr;

	public:
		Appointment();
		Appointment(string, string, string, string, string);

	// Methods
		string getTime(); // get appointment time
		void setTime(string, string, string, string); // set appointment time, int starthr, startmin, endhr, endmin
		string toString();
};
#endif

