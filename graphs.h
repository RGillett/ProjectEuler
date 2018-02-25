/*******************************************************************************
* Author: Ryan Gillett
*******************************************************************************/
#ifndef GRAPHS
#define GRAPHS

#include <vector>
#include <queue>

class Dijkstra
{
private:
    struct Coordinates
    {
        int x;
        int y;
        int* location;
        Coordinates(int i, int j, int* pointer)
        {
            x = i;
            y = j;
            location = pointer;
        }
    };

    int distanceSums[80][80];

    class LessThan
    {
    public:
        bool operator() (const Coordinates &LHS, const Coordinates &RHS)
        {
            return *(LHS.location) > *(RHS.location);
        }
    };

    bool reachedGoal(const Coordinates &CURRENT_COORDINATES, const int &GOAL_X, const int &GOAL_Y)
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

public:
    int dijkstra80x80(const int Q[][80],const int &START_X, const int &START_Y, const int &GOAL_X, const int &GOAL_Y, const bool &LEFT, const bool &UP, const bool &RIGHT, const bool &DOWN)
    {
        std::priority_queue<Coordinates, std::vector<Coordinates>, LessThan> open;
        bool visited[80][80];

        for (int i = 0; i < 80; ++i)
        {
            for (int j = 0; j < 80; ++j)
            {
                distanceSums[i][j] = 1000000;
                visited[i][j] = false;
            }
        }

        distanceSums[START_X][START_Y] = Q[START_X][START_Y];

        open.push(Coordinates(START_X, START_Y, &distanceSums[START_X][START_Y]));

        Coordinates currentNode = open.top();

        while(!reachedGoal(currentNode, GOAL_X, GOAL_Y))
        {
            currentNode = open.top();
            open.pop();
            visited[currentNode.x][currentNode.y] = true;

            if (LEFT && !visited[currentNode.x][currentNode.y-1] && currentNode.y > 0)
            {
                if(distanceSums[currentNode.x][currentNode.y-1] > Q[currentNode.x][currentNode.y-1] + distanceSums[currentNode.x][currentNode.y])
                {
                    distanceSums[currentNode.x][currentNode.y-1] = Q[currentNode.x][currentNode.y-1] + distanceSums[currentNode.x][currentNode.y];
                    open.push(Coordinates(currentNode.x, currentNode.y-1, &distanceSums[currentNode.x][currentNode.y-1]));
                }
            }
            if (UP && !visited[currentNode.x-1][currentNode.y] && currentNode.x > 0)
            {
                if(distanceSums[currentNode.x-1][currentNode.y] > Q[currentNode.x-1][currentNode.y] + distanceSums[currentNode.x][currentNode.y])
                {
                    distanceSums[currentNode.x-1][currentNode.y] = Q[currentNode.x-1][currentNode.y] + distanceSums[currentNode.x][currentNode.y];
                    open.push(Coordinates(currentNode.x-1, currentNode.y, &distanceSums[currentNode.x-1][currentNode.y]));
                }
            }
            if (RIGHT && !visited[currentNode.x][currentNode.y+1] && currentNode.y < 79)
            {
                if(distanceSums[currentNode.x][currentNode.y+1] > Q[currentNode.x][currentNode.y+1] + distanceSums[currentNode.x][currentNode.y])
                {
                    distanceSums[currentNode.x][currentNode.y+1] = Q[currentNode.x][currentNode.y+1] + distanceSums[currentNode.x][currentNode.y];
                    open.push(Coordinates(currentNode.x, currentNode.y+1, &distanceSums[currentNode.x][currentNode.y+1]));
                }
            }
            if (DOWN && !visited[currentNode.x+1][currentNode.y] && currentNode.x < 79)
            {
                if(distanceSums[currentNode.x+1][currentNode.y] > Q[currentNode.x+1][currentNode.y] + distanceSums[currentNode.x][currentNode.y])
                {
                    distanceSums[currentNode.x+1][currentNode.y] = Q[currentNode.x+1][currentNode.y] + distanceSums[currentNode.x][currentNode.y];
                    open.push(Coordinates(currentNode.x+1, currentNode.y, &distanceSums[currentNode.x+1][currentNode.y]));
                }
            }
        }

        return distanceSums[currentNode.x][currentNode.y];
    }
};

#endif // GRAPHS