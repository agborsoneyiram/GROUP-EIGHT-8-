//GROUP 8
//10955078 - EYIRAM ABA AGBORSON
//10931601 - MICHELLE ABUN MURNA
//- ASHESI CRENTSIL
//- MICHELLE OWUSU
//- BERNICE BOATENG

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    int currentFloor = 1;
    int desiredFloor;
    char choice;
    bool doorOpen = false;
    int number_of_floors = 5;

    while (true) {
        // TO DISPLAY THE CURRENT FLOOR TO USERS OUTSIDE THE ELEVATOR
        cout << "Elevator currently on floor " << currentFloor << endl;

        // TO OPEN THE ELEVATOR DOOR
        cout << "Door closed. Press '0' to open door" << endl;
        cin >> choice;
        if (choice == '0') {
            doorOpen = true;
        }

        while (true) {
            cout << "You are currently on floor " << currentFloor << endl;
            cout << "There are 5 floors in this building " << endl;

            cout << "Which floor would you like to go to? ";
            cin >> desiredFloor;
            cout << endl;

            if (desiredFloor > number_of_floors) {
                cout << "This building does not have a " << desiredFloor << "th floor" << endl;
                cout << "Which floor would you like to go to?";
                cin >> desiredFloor;
                cout << endl;
            }

            if (desiredFloor > currentFloor) {
                cout << "Going up..." << endl;

                while (currentFloor < desiredFloor) {
                    currentFloor++;
                    cout << "Now on floor " << currentFloor << endl;
                }
            }

            else if (desiredFloor < currentFloor) {
                cout << "Going down..." << endl;

                while (currentFloor > desiredFloor) {
                    currentFloor--;
                    cout << "Now on floor " << currentFloor << endl;
                }
            }

            else {
                cout << "You are already on floor " << currentFloor << endl;
            }

            cout << "You have arrived at floor " << currentFloor << endl;

            // FIND OUT FROM THE USER IF THEY WISH TO MOVE TO A DIFFERENT FLOOR
            cout << "Do you want to move to another floor? (y/n)";
            cin >> choice;

            if (choice == 'n') {
                // TO AUTOMATICALLY CLOSE THE ELEVATOR DOOR
                doorOpen = true;
                cout << "Door opening..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << "Door closing..." << endl;
                doorOpen = false;
                cout << "Thanks for using the elevator!" << endl;
                return 0;
            }
        }
    }
}
