#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 6

char play_actions[] = {
        ACTION_MOVE_U,ACTION_DASH_R,ACTION_DASH_D,ACTION_SPLASH,ACTION_MOVE_L,ACTION_MOVE_L
};

char get_action_1()
{
    static int i = 0;
    char ret_val = 0;

    ret_val = play_actions[i];
    i++;
    if (i >= MAX_PLAY_ACTION)
    {
        i = 0;
    } 
    return (ret_val);
}