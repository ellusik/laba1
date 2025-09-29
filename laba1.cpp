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
