#include "Robot.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


const float speed= 1.0f; // speed adjustment

Robot::Robot(){
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
    angle = 0;
    isMoving = false;
}

void Robot::move(){
    isMoving = true;
    cout << "CompBot started moving!" << endl;
    float rad = angle * (3.14 / 180.0);
    vx = speed * cos(rad);
    vy = speed * sin(rad);
}
void Robot::stop(){
    isMoving = false;
    cout << "CompBot stopped moving!" << endl;
}
void Robot::turn(float degrees){
    angle += degrees;
    if (angle >= 360) angle -= 360; 
    if (angle < 0) angle += 360;
    cout << "CompBot turned to " << angle << " degrees." << endl;

    if (isMoving){
       float rad = angle * (3.14 / 180.0);
        vx = speed * cos(rad);
        vy = speed * sin(rad);
    }
}
void Robot::update(){
    if (isMoving){
        x += vx;
        y += vy;
        
        std::ofstream log("path.csv", std::ios::app);
        if(log.is_open()){
            log << x << "," << y << "\n";
        }
        log.close();
    }
}
void Robot::printState(){
    cout << "Position: (" << x << ", "<< y <<")" << endl;
    cout << "Angle: " << angle << " degrees" << endl;
    cout << "Velocity: (" << vx << ", "<< vy << ")" << endl;
    cout << "Status: " << (isMoving ? "Moving" : "Stopped") << endl;
}