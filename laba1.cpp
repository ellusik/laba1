#include <iostream>
#include <string>
using namespace std;

string pipe_name = "";
double pipe_length = 0;
int pipe_diameter = 0;
bool pipe_repair = false;

string station_name = "";
int station_workshops = 0;
int station_working = 0;

bool checkNumber() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error! Enter number: ";
        return false;
    }
    return true;
}

void showMenu() {
    cout << "\n1. Add pipe\n2. Add station\n3. View all\n";
    cout << "4. Toggle pipe repair\n5. Edit workshops\n6. Exit\nChoice: ";
}

int main() {
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
        if (!checkNumber()) continue;
        
        if (choice == 1) {
            cout << "Pipe name: ";
            cin >> pipe_name;
            
            cout << "Length: ";
            cin >> pipe_length;
            while (!checkNumber() || pipe_length <= 0) {
                cout << "Error! Length must be positive number: ";
                cin >> pipe_length;
            }
            
            cout << "Diameter: ";
            cin >> pipe_diameter;
            while (!checkNumber() || pipe_diameter <= 0) {
                cout << "Error! Diameter must be positive number: ";
                cin >> pipe_diameter;
            }
            
            pipe_repair = false;
            cout << "Pipe added!\n";
        }

        else if (choice == 2) {
            cout << "Station name: ";
            cin >> station_name;
            
            cout << "Total workshops: ";
            cin >> station_workshops;
            while (!checkNumber() || station_workshops <= 0) {
                cout << "Error! Must be positive number: ";
                cin >> station_workshops;
            }
            
            cout << "Working workshops: ";
            cin >> station_working;
            while (!checkNumber() || station_working < 0 || station_working > station_workshops) {
                cout << "Error! Working must be from 0 to " << station_workshops << ": ";
                cin >> station_working;
            }
            
            cout << "Station added!\n";
        }