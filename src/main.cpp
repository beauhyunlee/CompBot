#include "Robot.h"
#include <chrono>
#include <thread>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <atomic>

using namespace std;
atomic<bool> running(true); // controls update thread

void autoUpdate(Robot* r){
    while (running){
        r->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main()
{
    Robot r;
    string input;
    cout<<"Entering the control panel for CompBot (type 'help'): "<< endl;

    std::ofstream clear("data/path.csv", std::ios::trunc); //clears previous data
    clear.close();

    system("/opt/anaconda3/envs/compbot/bin/python scripts/animate_path.py &");


    //start background update
    thread updater(autoUpdate, &r);

    while (true)
    {
        cout<< "> ";
        getline(cin, input);
        stringstream ss(input);
        string command;
        ss >> command;

        if (command == "move") r.move();

        else if (command == "stop") r.stop();
        else if (command == "turn")
        {
            float angle;
            if (ss >> angle)
                r.turn(angle);
            else
                cout << "input a viable turn <angle>" << endl;
        }
        else if (command == "status") r.printState();
        else if (command == "help"){
            cout << "🛠 Available Commands:" << endl;
            cout << "  move         — start moving" << endl;
            cout << "  stop         — stop moving" << endl;
            cout << "  turn <deg>   — rotate robot by degrees" << endl;
            cout << "  status       — print current state" << endl;
            cout << "  quit         — exit the program" << endl;
        } else if (command == "quit"){
            cout << "CompBot says bye!" << endl;
            running = false;
            break;
        } else{
            cout << "Unknown command. Type 'help' for options." << endl;
        }
    }
    updater.join(); // wait for background thread to finish
    cout << "CompBot is shutting down..." << endl;
    return 0;
}
