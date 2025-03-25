#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 6

char play_actions_3[] = {ACTION_MOVE_D,ACTION_DASH_L,ACTION_DASH_U,ACTION_SPLASH,ACTION_DASH_L,ACTION_BOMB};

char get_action_3()
{
    static int i       = 0;
    char       ret_val = 0;

    ret_val = play_actions_3[i];
    i++;
    if (i >= MAX_PLAY_ACTION)
    {
        i = 0;
    }
    return (ret_val);
}