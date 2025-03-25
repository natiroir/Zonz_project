#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 6

char play_actions_4[] = {ACTION_MOVE_R,ACTION_TELEPORT_U,ACTION_DASH_D,ACTION_TELEPORT_R,ACTION_DASH_U,ACTION_SPLASH};

char get_action_4()
{
    static int i       = 0;
    char       ret_val = 0;

    ret_val = play_actions_4[i];
    i++;
    if (i >= MAX_PLAY_ACTION)
    {
        i = 0;
    }
    return (ret_val);
}