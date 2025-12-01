#ifndef ROBOT_H
#define ROBOT_H
#include <fstream>
class Robot{
friend void autoUpdate(Robot* r); // allow thread to call private update
private:
    float x,y; // current position
    float vx, vy; // velocity components
    float angle; // direction in degrees
    bool isMoving; // is robot moving
    void update(); // update position

public:
    Robot(); // construtor
    void move(); // start moving
    void stop(); // stop moving
    void turn(float angle); // rotate robot
    void printState(); // output robot state
};
#endif