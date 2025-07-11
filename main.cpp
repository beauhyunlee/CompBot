#include "Robot.h"
#include <chrono>
#include <thread>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    Robot r;
    string input;

    std::ofstream clear("path.csv", std::ios::trunc); //clears previous data
    clear.close();

    while (true)
    {
        getline(cin, input);

        stringstream ss(input);
        string command;
        ss >> command;

        if (command == "move")
        {
            r.move();
        }
        else if (command == "stop")
        {
            r.stop();
        }
        else if (command == "turn")
        {
            float angle;
            if (ss >> angle)
                r.turn(angle);
            else
                cout << "input a viable turn <angle>" << endl;
        }
        else if (command == "update")
        {
            r.update();
        }
        else if (command == "status")
        {
            r.printState();
        } else if (command == "help"){
            cout << "🛠 Available Commands:" << endl;
            cout << "  move         — start moving" << endl;
            cout << "  stop         — stop moving" << endl;
            cout << "  turn <deg>   — rotate robot by degrees" << endl;
            cout << "  update       — update position" << endl;
            cout << "  status       — print current state" << endl;
            cout << "  quit         — exit the program" << endl;
        } else if (command == "quit"){
            cout << "CompBot says bye!" << endl;
            break;
        } else{
            cout << "Unknown command. Type 'help' for options." << endl;
        }
    }

   
    return 0;
}
