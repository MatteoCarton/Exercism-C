#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot;
    robot_position_t startPosition;

    startPosition.x = x;
    startPosition.y = y;
    robot.direction = direction;
    robot.position = startPosition;

    return (robot);
}

static void change_direction(robot_status_t *robot, char c)
{
    if (c != 'L' && c != 'R')
        return ;
    if (robot->direction == DIRECTION_NORTH)
    {
        if (c == 'L')
             robot->direction = DIRECTION_WEST;
        if (c == 'R')
             robot->direction = DIRECTION_EAST;
    }
    else if (robot->direction == DIRECTION_EAST)
    {
        if (c == 'L')
             robot->direction = DIRECTION_NORTH;
        if (c == 'R')
             robot->direction = DIRECTION_SOUTH;
    }
    else if (robot->direction == DIRECTION_SOUTH)
    {
        if (c == 'L')
             robot->direction = DIRECTION_EAST;
        if (c == 'R')
             robot->direction = DIRECTION_WEST;
    }
    else if (robot->direction == DIRECTION_WEST)
    {
        if (c == 'L')
             robot->direction = DIRECTION_SOUTH;
        if (c == 'R')
             robot->direction = DIRECTION_NORTH;
    }
    return ;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    int i = 0;

    while (commands[i] != '\0')
    {
        change_direction(robot, commands[i]);
        if (commands[i] == 'A')
        {
            if (robot->direction == DIRECTION_NORTH)
                robot->position.y++;
            else if (robot->direction == DIRECTION_EAST)
                robot->position.x++;
            else if (robot->direction == DIRECTION_SOUTH)
                robot->position.y--;
            else if (robot->direction == DIRECTION_WEST)
                robot->position.x--;
        }
        i++;
    }
}
