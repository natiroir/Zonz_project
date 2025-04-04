#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "actions.h"
#include "param.h"
#include "player.h"
#include "world.h"

/* !!!!!!!!!!!!!!!! MAP !!!!!!!!!!!!!!!!!!!!! */
uint8_t mapmem[MAP_SIZE * MAP_SIZE] = {255};

/*  PLAYERS */
t_player* players[MAX_PLAYERS] = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_create_players()
{
    int i = 0;

    for (i = 0; i < 2; i++)
    {
        players[i] = (t_player*)malloc(sizeof(t_player));
        player_init(players[i], i);
        world_paint_spot(players[i]->x, players[i]->y, players[i]->id);
    }
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_paint_spot(uint32_t x, uint32_t y, uint32_t num)
{
    if (x > MAP_SIZE || y > MAP_SIZE) {
        fprintf(stderr, "Coordonnées (%u, %u) hors limites\n", x, y);
        return;
    }
    uint32_t pos = y * MAP_SIZE + x;
    mapmem[pos]  = num;
    //printf(" Pixel %d peint par Joueur %d\n", pos, num);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_get_winner()
{
    // ici du code a qui fonctionne
}
