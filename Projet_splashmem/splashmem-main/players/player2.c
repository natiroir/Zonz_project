#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 12

char play_actions_2[] = {
    ACTION_BOMB, ACTION_TELEPORT_L, ACTION_BOMB, ACTION_TELEPORT_L, ACTION_MOVE_L, ACTION_TELEPORT_L,
    ACTION_MOVE_L, ACTION_TELEPORT_L,ACTION_TELEPORT_D , ACTION_BOMB , ACTION_STILL,
};

char get_action_2()
{
    static int i       = 0;
    char       ret_val = 0;

    ret_val = play_actions_2[i];
    i++;
    if (i >= MAX_PLAY_ACTION)
    {
        i = 0;
    }
    return (ret_val);
}