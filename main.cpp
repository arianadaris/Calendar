/*
    Author: Ariana Rajewski
    Date: 4/17/2021
    Description: This calendar allows the user to decide how many days it lists and what day the calendar starts on.
        It also has a menu system, allowing the user to display the calendar, dsiplay a specific day,
        add or remove an errand, and save the calendar to a text file of their choice.
*/
#include "Calendar.h"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main(int argc, char** argv)
{
    int input, num, start, daySelected, errandType, errandSelected;
    string title, descr, startHr, startMin, endHr, endMin, filename;
    Calendar* calendar = NULL;

    // Prompt user with Welcome Message
    cout << "Welcome to the Calendar app.\n" << endl;

    // Prompt user with Build Calendar or Exit decision
    while (1)
    {
        cout << "1. Build a Calendar\n2. Exit\n\nSelection >> ";
        cin >> input;

        if (input == 1) // Build Calendar
        {
            cout << "\nBuilding a new calendar..." << endl;
            
            //Prompt for title
            cout << "Calendar Title: ";
            cin >> title;

            // Prompt for number of days
            cout << "Number of days: ";
            cin >> num;

            // Prompt for start day
            cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n6. Saturday\n7. Sunday" << endl;
            cout << "Start day: ";
            cin >> start;

            calendar = new Calendar(title, num, start); // Create new calendar object
            cout << "\nA new calendar has been created.\n" << endl;

            break;
        }
        else if (input == 2) // Exit
            return 0;
    }

    while (1)
    {
        // Prompt user for Calendar decision
        cout << "What would you like to do?\n" << endl;
        cout << "1. Display Calendar\n2. Display a Single Day\n3. Add an Errand\n4. Delete an Errand\n5. Save to a file\n0. Exit\n\nSelection >> ";
        cin >> input;
        cout << endl;

        // Calendar decision
        switch (input)
        {
            case 1: // Display Calendar
               cout << "Here is a view of your current calendar->" << endl; // Print calendar
               calendar->display();
               cout << endl;
               break;

            case 2: // Display a Single Day on the Calendar
                while (1)
                {
                    // Prompt user to select day to view
                    cout << "Which day would you like to view? (1 - " << num << ")\n(0 - Return to Menu)\n\nSelection >> ";
                    cin >> daySelected;
                    cout << endl;

                    if (daySelected == 0) // Return user to main menu
                        break;
                    else // Print the day that the user selected
                        cout << calendar->getDay(daySelected)->toString() << "\n" << endl;
                    break;
                }
                break;

            case 3: // Add an Errand
                // Promp user to select a day to add an errand to
                calendar->display();
                cout << "\nWhich day would you like to add an Errand to? (1 - " << num << ")\n\nSelection >> ";
                cin >> daySelected;
                
                while (1)
                {
                    // Prompt user to select a type of errand (reminder or appointment)
                    cout << "\n\nWhat type of Errand would you like to add?\n1. Reminder\n2. Appointment\n0. Return to Menu\n\nSelection >> ";
                    cin >> errandType;
                    cout << endl;

                    switch (errandType)
                    {
                        case 1: // Enter a Reminder
                            // Prompt user to enter a description for the reminder
                            cout << "Please enter a description. ";
                            cin.ignore();
                            getline(cin, descr);

                            // Add the reminder to the calendar
                            calendar->getDay(daySelected)->addReminder(descr);
                            cout << "\nYour reminder has been added.\n" << endl;
                            break;
                        
                        case 2: // Enter an Appointment
                            // Prompt the user for start time and end time (24 hour clock)
                            cout << "Please enter a start time hour (24 hour clock): ";
                            cin >> startHr;
                            cout << "Please enter start time minutes: ";
                            cin >> startMin;
                            cout << "Please enter an end time hour (24 hour clock): ";
                            cin >> endHr;
                            cout << "Please enter end time minutes: ";
                            cin >> endMin;

                            // Prompt user to enter a description for the appointment
                            cout << "Please enter a description. ";
                            cin.ignore();
                            getline(cin, descr);

                            // Add the appointment to the calendar
                            calendar->getDay(daySelected)->addAppointment(descr, startHr, startMin, endHr, endMin);
                            cout << "\nYour appointment for " << calendar->getDay(daySelected)->getDayName() << " has been added.\n" << endl;
                            break;
                        case 0:
                            break;
                    }
                    break;
                }
                break;

            case 4: // Delete an Errand
                // Prompt the user to select a day to remove an errand from
                calendar->display();
                cout << "\nWhich day would you like to remove an errand from? (1 - " << num << ")\n(0 - Return to Menu)\n\nSelection >> ";
                cin >> daySelected;
                cout << endl;

                while (1)
                {
                    if (daySelected == 0) // Return user to main menu
                        break;
                    else if (calendar->getDay(daySelected)->getNumErrand() == 0) // Return no errands if there are no errands set for this day
                    {
                        cout << "There are no errands set for this day! Returning to main menu.\n" << endl;
                        break;
                    }
                    else
                    {
                        // Print the errands associated with the day
                        cout << calendar->getDay(daySelected)->toString() << "\n\nErrands:" << endl;
                        for (int i = 1; i <= calendar->getDay(daySelected)->getNumErrand(); i++)
                        {
                            cout << (i) << ". " << calendar->getDay(daySelected)->getErrand(i)->toString() << endl;
                        }

                        // Prompt the user to enter the errand they would like to delete
                        cout << "\nWhich errand would you like to delete?\n(0 - Return to Menu)\n\nSelection >> ";
                        cin >> errandSelected;
                        cout << endl;
                        
                        while (1)
                        {
                            if (errandSelected == 0) // Return to main menu
                                break;
                            else
                            {
                                // Remove the errand from the day
                                calendar->getDay(daySelected)->removeErrand(errandSelected);
                                cout << "Your errand has been removed.\n" << endl;
                            }
                            break;
                        }
                    }
                    break;
                }
                break;

            case 5: // Save to a File
                // Prompt the user to enter a file name to save the calendar to
                cout << "To save your calendar to a file, please enter a filename to store to. ";
                cin >> filename;

                // Save the calendar to the file
                calendar->saveToFile(filename);
                cout << "\nYour calendar has been saved to " << filename << ".\n" << endl;
                break;

            case 0: // Exit
                delete calendar; // destruct calendar object when exiting main menu/closing program
                return 0;

            default: // Option was not valid
                cout << "Please select a valid option." << endl;
                break;
        }
    }

    delete calendar; // destruct calendar object when closing program
    return 0;
}
