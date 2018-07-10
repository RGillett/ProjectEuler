/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef DIJKSTRA
#define DIJKSTRA

class Dijkstra
{
private:
    int distanceSums[80][80];
    class Coordinates
    {
    public:
        int x;
        int y;
        int* location;
        Coordinates(int i, int j, int* pointer);
    };

    class LessThan
    {
    public:
        bool operator() (const Coordinates &LHS, const Coordinates &RHS);
    };

    bool reachedGoal(const Coordinates &CURRENT_COORDINATES, const int &GOAL_X, const int &GOAL_Y);

public:
    int dijkstra80x80(const int DISTANCES[][80], const int &START_X, const int &START_Y, const int &GOAL_X, const int &GOAL_Y, const bool &LEFT, const bool &UP, const bool &RIGHT, const bool &DOWN);
};

#endif // DIJKSTRA