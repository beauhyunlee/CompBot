#include "Robot.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cmath>
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
    cout << "CompBot has started moving..." << endl;
    float rad = angle * (M_PI / 180.0f);
    vx = speed * cos(rad);
    vy = speed * sin(rad);
}
void Robot::stop(){
    isMoving = false;
    cout << "CompBot has stopped moving..." << endl;
}
void Robot::turn(float degrees){
    angle += degrees;
    
    // [0, 360]
    if (angle >= 360) angle -= 360; 
    if (angle < 0) angle += 360;
    cout << "CompBot turned to " << angle << " degrees." << endl;
    // rotate other direction take the transpose
    
    if (isMoving){
       float rad = angle * (M_PI / 180.0f);
        vx = speed * cos(rad);
        vy = speed * sin(rad);
    }
}
void Robot::update(){
    if(!isMoving) return;
    x += vx;
    y += vy;
    ofstream log("data/path.csv", ios::app);
    if(log.is_open()){
        log << x << "," << y << "\n";
    }
}
void Robot::printState(){
    cout << "Position: (" << x << ", "<< y <<")" << endl;
    cout << "Angle: " << angle << " degrees" << endl;
    cout << "Velocity: (" << vx << ", "<< vy << ")" << endl;
    cout << "Status: " << (isMoving ? "Moving" : "Stopped") << endl;
}