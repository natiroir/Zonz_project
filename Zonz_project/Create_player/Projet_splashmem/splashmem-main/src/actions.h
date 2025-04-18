#ifndef __ACTIONS__
#define __ACTIONS__

#include "player.h"

#define NB_CREDIT_DASH 10
#define NB_CREDIT_TELEP 2
#define NB_CREDIT_DASH 10


enum action
{
    ACTION_STILL,
    ACTION_MOVE_L,
    ACTION_MOVE_R,
    ACTION_MOVE_U,
    ACTION_MOVE_D,
    ACTION_DASH_L,
    ACTION_DASH_R,
    ACTION_DASH_U,
    ACTION_DASH_D,
    ACTION_TELEPORT_L,
    ACTION_TELEPORT_R,
    ACTION_TELEPORT_U,
    ACTION_TELEPORT_D,
    ACTION_SPLASH,
    ACTION_BOMB,
    ACTION_MOVE_UP_RIGHT,
    ACTION_MOVE_UP_LEFT,
    ACTION_MOVE_DOWN_RIGHT,
    ACTION_MOVE_DOWN_LEFT,
    ACTION_NUMBER
};

void actions_do(t_player *p_player, enum action act_id);
void actions_init();
int32_t get_credit_player(t_player *p_player);
#endif
