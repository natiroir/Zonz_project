#include "player.h"
#include "param.h"
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "main.h"

int start_pos_x[] = {MAP_SIZE / 4, MAP_SIZE * 3 / 4};
int start_pos_y[] = {MAP_SIZE / 2, MAP_SIZE / 2};

int start_pos_x_box[] = {MAP_SIZE / 2, MAP_SIZE / 2 + 1};
int start_pos_y_box[] = {MAP_SIZE / 2, MAP_SIZE / 2 + 1};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void player_init(t_player* p_player, uint8_t num)
{
    p_player->id      = num + 1;
    p_player->color   = 0;
    if(get_mode_game() == 0 )
    {
        /* Mode box */
        p_player->x = start_pos_x_box[num];
        p_player->y = start_pos_x_box[num];            
    }
    else
    {
        p_player->x = start_pos_x[num];
        p_player->y = start_pos_y[num];
    }
    p_player->credits = 1500;//P_CREDITS
    p_player->count   = 0;
}
