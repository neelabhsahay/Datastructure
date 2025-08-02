/*
* You are controlling a robot that is located somewhere in a room.
* The room is modeled as an m x n binary grid where 0 represents a
* wall and 1 represents an empty slot.
*
* The robot starts at an unknown location in the room that is guaranteed to
*  be empty, and you do not have access to the grid,
* but you can move the robot using the given API Robot.
*
* You are tasked to use the robot to clean the entire room
* (i.e., clean every empty cell in the room).
* The robot with the four given APIs can move forward,
* turn left, or turn right. Each turn is 90 degrees.
*
* When the robot tries to move into a wall cell,
* its bumper sensor detects the obstacle, and it stays on the current cell.
*
* Design an algorithm to clean the entire room using the following APIs:
*
*interface Robot {
*  // returns true if next cell is open and robot moves into the cell.
*  // returns false if next cell is obstacle and robot stays on the current cell.
*  boolean move();
*
*  // Robot will stay on the same cell after calling turnLeft/turnRight.
*  // Each turn will be 90 degrees.
*  void turnLeft();
*  void turnRight();
*
*  // Clean the current cell.
*   void clean();
* }
* Note that the initial direction of the robot will be facing up.
* You can assume all four edges of the grid are all surrounded by a wall.
*/


#include<iostream>

using namespace std;

bool
robotCleanRoom(vector<vector<int>> &grid, int row, int col)
{
    return false;
}

int main()
{
    vector<vector<int>> grid = {{1,1,1,1,1,0,1,1},
                                {1,1,1,1,1,0,1,1},
                                {1,0,1,1,1,1,1,1},
                                {0,0,0,1,0,0,0,0},
                                {1,1,1,1,1,1,1,1}};
    int row = 1;
    int col = 3;
    
    bool result = robotCleanRoom(grid, row, col);
    cout << "Robot can " << (result == true? "":"NOT") << " clean the room.\n";
    return 0;
}
