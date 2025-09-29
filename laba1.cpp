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
        else if (choice == 3) {
            if (pipe_name != "") {
                cout << "PIPE: " << pipe_name << " " << pipe_length << "km " << pipe_diameter << "mm ";
                cout << (pipe_repair ? "REPAIR" : "OK") << endl;
            } else {
                cout << "No pipe\n";
            }
            
            if (station_name != "") {
                cout << "STATION: " << station_name << " " << station_working << "/" << station_workshops << " working" << endl;
            } else {
                cout << "No station\n";
            }
        }
        else if (choice == 4) {
            if (pipe_name != "") {
                pipe_repair = !pipe_repair;
                cout << "Pipe repair: " << (pipe_repair ? "YES" : "NO") << endl;
            } else {
                cout << "No pipe to edit!\n";
            }
        }
        else if (choice == 5) {
            if (station_name != "") {
                cout << "1. Start workshop\n2. Stop workshop\nChoice: ";
                int c;
                cin >> c;
                if (!checkNumber()) continue;
                
                if (c == 1) {
                    if (station_working < station_workshops) {
                        station_working++;
                        cout << "Workshop started. Now: " << station_working << endl;
                    } else {
                        cout << "All workshops already working!\n";
                    }
                }
                else if (c == 2) {
                    if (station_working > 0) {
                        station_working--;
                        cout << "Workshop stopped. Now: " << station_working << endl;
                    } else {
                        cout << "No workshops working!\n";
                    }
                }
                else {
                    cout << "Wrong choice!\n";
                }
            } else {
                cout << "No station to edit!\n";
            }
        }
        else if (choice == 6) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Wrong choice! Use 1-6\n";
        }
    }
    
    return 0;
}