/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#include "Dijkstra.h"

#include <vector>
#include <queue>

int Dijkstra::dijkstra80x80(const int DISTANCES[][80], const int &START_X, const int &START_Y, const int &GOAL_X, const int &GOAL_Y, const bool &LEFT, const bool &UP, const bool &RIGHT, const bool &DOWN)
{
    std::priority_queue<Coordinates, std::vector<Coordinates>, LessThan> open;
    bool visited[80][80];

    for (int i = 0; i < 80; ++i)
    {
        for (int j = 0; j < 80; ++j)
        {
            distanceSums[i][j] = 1600000; // Highest value in graph is 9999: shortest path will be no more than 9999*(80+79)
            visited[i][j] = false;
        }
    }

    distanceSums[START_X][START_Y] = DISTANCES[START_X][START_Y];

    open.push(Coordinates(START_X, START_Y, &distanceSums[START_X][START_Y]));

    Coordinates currentNode = open.top();

    while(!reachedGoal(currentNode, GOAL_X, GOAL_Y))
    {
        currentNode = open.top();
        open.pop();

        if (!visited[currentNode.x][currentNode.y])
        {
            visited[currentNode.x][currentNode.y] = true;

            Coordinates adjacencies[4] =
            {
                Coordinates(currentNode.x, currentNode.y-1, &distanceSums[currentNode.x][currentNode.y-1]),
                Coordinates(currentNode.x-1, currentNode.y, &distanceSums[currentNode.x-1][currentNode.y]),
                Coordinates(currentNode.x, currentNode.y+1, &distanceSums[currentNode.x][currentNode.y+1]),
                Coordinates(currentNode.x+1, currentNode.y, &distanceSums[currentNode.x+1][currentNode.y])
            };
            bool allowedEdges[4] = {LEFT,UP,RIGHT,DOWN};
            bool coordinatesWithinBounds[4] = {currentNode.y > 0, currentNode.x > 0, currentNode.y < 79, currentNode.x < 79};

            for (int i = 0; i < 4; i++)
            {
                if (allowedEdges[i] && coordinatesWithinBounds[i])
                {
                    if (*adjacencies[i].location > DISTANCES[adjacencies[i].x][adjacencies[i].y] + *currentNode.location)
                    {
                        *adjacencies[i].location = DISTANCES[adjacencies[i].x][adjacencies[i].y] + *currentNode.location;
                    }
                    open.push(adjacencies[i]);
                }
            }
        }
    }

    return distanceSums[currentNode.x][currentNode.y];
}

Dijkstra::Coordinates::Coordinates(int i, int j, int* pointer)
{
    x = i;
    y = j;
    location = pointer;
}

bool Dijkstra::LessThan::operator() (const Coordinates &LHS, const Coordinates &RHS)
{
    return *(LHS.location) > *(RHS.location);
}

bool Dijkstra::reachedGoal(const Coordinates &CURRENT_COORDINATES, const int &GOAL_X, const int &GOAL_Y)
{
    bool yMatches = CURRENT_COORDINATES.y == GOAL_Y;
    bool xMatches = CURRENT_COORDINATES.x == GOAL_X;
    bool reachedGoal;

    if (GOAL_X == -1)
    {
        reachedGoal = yMatches;
    }
    else if (GOAL_Y == -1)
    {
        reachedGoal = xMatches;
    }
    else
    {
        reachedGoal = xMatches && yMatches;
    }

    return reachedGoal;
}