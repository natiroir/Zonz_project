#include "actions.h"
#include "param.h"
#include "world.h"
#include "stdio.h"

static uint32_t mem_x = 0;
static uint32_t mem_y = 0;

void actions_init()
{

}

void actions_do(t_player *p_player, enum action act_id)
{
    static uint32_t mem_player = 0;
    static uint32_t mem_player_y = 0;
    static uint32_t id_player = 0;
    uint8_t i = 0;
    static int32_t credits_pl = 0;
    static uint8_t bombe_retard = 0;
    static uint8_t counter_bombe = 0;
    static uint8_t declenche_bombe = 0;

    mem_player = p_player->x;
    mem_player_y = p_player->y;
    credits_pl = p_player->credits;
    id_player = p_player->id;

    switch (act_id)
    {
    case ACTION_STILL:
        credits_pl--; // Réduction des crédits
        break;
    case ACTION_MOVE_L:
    if (mem_player <= 0)
    {
        mem_player = 100;
    }
    world_paint_spot((mem_player-1), mem_player_y, id_player);
    p_player->x = mem_player-1;
    //printf("x = %d ", p_player->x);
    credits_pl--;
    break;
    case ACTION_MOVE_R:
    if (mem_player >= MAP_SIZE)
    {
        mem_player = 0;
    }
    world_paint_spot(mem_player+1, mem_player_y, id_player);
    p_player->x = mem_player+1;
    credits_pl--;
    break;
    case ACTION_MOVE_U:
    if (mem_player_y <= 0)
    {
        mem_player_y = MAP_SIZE - 1;
    }
    world_paint_spot(mem_player, mem_player_y-1, id_player);
    p_player->y = mem_player_y-1;
    credits_pl--;
    break;
    case ACTION_MOVE_D: // modif
    if (mem_player_y >= MAP_SIZE - 1)
    {
        mem_player_y = 0;
    }
    else
    {
        mem_player_y++;
    }
    world_paint_spot(mem_player, mem_player_y, id_player);
    p_player->y = mem_player_y;
    credits_pl--;
    break;
    /******************************** DASH ***************************/
    case ACTION_DASH_L:
    for (i=0;i <8;i++)
    {  
        mem_player--;
        if (mem_player <= 0)
        {
            mem_player = 100;
        }
        world_paint_spot(mem_player, mem_player_y, id_player);
    }
    p_player->x = mem_player;
    credits_pl = credits_pl - 10;
    break;
    case ACTION_DASH_R :
    for (i=0;i <8;i++)
    {  
        mem_player++;
        if (mem_player >= MAP_SIZE)
        {
            mem_player = 0;
        }
        world_paint_spot(mem_player, mem_player_y, id_player);
    }
    p_player->x = mem_player;
    credits_pl = credits_pl - 10;
    break;
    case ACTION_DASH_U:
    for (i=0;i <8;i++)
    {  
        if (mem_player_y == 0) // Vérifie la limite haute de la carte
        {
            mem_player_y = MAP_SIZE - 1; // Revient en bas si on dépasse la carte
        }
        else
        {
            mem_player_y--; // Décrémente la position Y
        }
        world_paint_spot(mem_player, mem_player_y, id_player);
    }
    p_player->y = mem_player_y;
    credits_pl = credits_pl - 10;
    break;
    case ACTION_DASH_D: // semble ok
    for (i=0;i <8;i++)
    {  
        mem_player_y++;
        if (mem_player_y >= MAP_SIZE - 1)
        {
            mem_player_y = 0;
        }
        world_paint_spot(mem_player, mem_player_y, id_player);
    }
    p_player->y = mem_player_y;
    credits_pl = credits_pl - 10;
    break;
    /**************** TELEPORT ****************************/
    case ACTION_TELEPORT_L:
    if (mem_player <= 0)
    {
        mem_player = 100;
    }
    world_paint_spot(mem_player-8, mem_player_y, id_player);
    p_player->x = mem_player-8;
    credits_pl = credits_pl - 2;
    break;
    case ACTION_TELEPORT_R:
    if (mem_player >= MAP_SIZE)
    {
        mem_player = 0;
    }
    world_paint_spot(mem_player+8, mem_player_y, id_player);
    p_player->x = mem_player+8;
    credits_pl = credits_pl - 2;
    break;
    case ACTION_TELEPORT_U:
    if (mem_player_y == 0) // Vérifie la limite haute de la carte
    {
        mem_player_y = MAP_SIZE - 1; // Revient en bas si on dépasse la carte
    }
    else
    {
        mem_player_y = mem_player_y - 8; // Décrémente la position Y
    }
    world_paint_spot(mem_player, mem_player_y, id_player);
    p_player->y = mem_player_y;
    credits_pl = credits_pl - 2;
    break;
    case ACTION_TELEPORT_D:
    if (mem_player +8 >= MAP_SIZE)
    {
        mem_player = 0;
    }
    world_paint_spot(mem_player, mem_player_y+8, id_player);
    p_player->y = mem_player_y+8;
    credits_pl = credits_pl - 2;
    break;
    case ACTION_SPLASH:
    /* Parcours des colonnes autour du joueur*/
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)  // Parcours des lignes autour du joueur
        {
            int new_x = mem_player + dx;
            int new_y = mem_player_y + dy;

            /* Vérification des limites de la carte */
            if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE)
            {
                world_paint_spot(new_x, new_y, id_player); // Colorie avec la couleur du joueur
            }
        }
    }
    credits_pl -= 8; // Réduction des crédits
    break;
    case ACTION_BOMB:
    bombe_retard = 1;
    mem_x = mem_player;
    mem_y = mem_player_y;
    if(declenche_bombe == 1)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)  // Parcours des lignes autour du joueur
            {
                int new_x = mem_x + dx;
                int new_y = mem_y + dy;

                /* Vérification des limites de la carte */
                if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE)
                {
                    world_paint_spot(new_x, new_y, id_player); // Colorie avec la couleur du joueur
                }
            }
        }
        credits_pl -= 8;
        declenche_bombe = 0;
        bombe_retard = 0;
    }
    break;
    case ACTION_NUMBER:

    break;
    default:
        break;
    }
    if (bombe_retard == 1)
    {
        if (counter_bombe==12)
        {
            /* Bombe declenche au bout du 5 tours, 16 car fonction appele 4 fois */
            declenche_bombe = 1;
            counter_bombe = 0;
            //printf(" bombe declenche ");
        }
        counter_bombe ++;
    }

}
