#include "actions.h"
#include "param.h"
#include "world.h"
#include "stdio.h"

#define MAX_BOMBS 10

static uint8_t cpt_par_appell = 0;

typedef struct {
    uint32_t x;
    uint32_t y;
    uint8_t counter;
    uint32_t player_id;
} Bomb;

void actions_init()
{
}

void actions_do(t_player *p_player, enum action act_id)
{
    static uint32_t mem_player = 0; 
    static uint32_t mem_player_y = 0;
    static uint32_t id_player = 0;
    uint8_t i = 0;
    static Bomb bombs[MAX_BOMBS] = {0};
    static uint8_t bomb_nbr = 0;

    cpt_par_appell++;

    mem_player = p_player->x;
    mem_player_y = p_player->y;
    id_player = p_player->id;

    switch (act_id)
    {
        case ACTION_STILL:
            if(p_player->credits>=1){
            p_player->credits--;} // Réduction des crédits 
            break;
        case ACTION_MOVE_L:
        if(p_player->credits>=1)
        {
        if (mem_player <= 0)
        {
            mem_player = MAP_SIZE - 1;
        }
        world_paint_spot((mem_player-1), mem_player_y, id_player); 
        p_player->x = mem_player-1;
        p_player->credits--;}
        break;
        case ACTION_MOVE_R:
        if(p_player->credits>=1){
        if (mem_player >= MAP_SIZE)
        {
            mem_player = 0;
        }
        world_paint_spot(mem_player+1, mem_player_y, id_player); 
        p_player->x = mem_player+1;
        p_player->credits--;}
        break;
        case ACTION_MOVE_U:
        if(p_player->credits>=1){
        if (mem_player_y <= 0)
        {
            mem_player_y = MAP_SIZE - 1;
        }
        world_paint_spot(mem_player, mem_player_y-1, id_player);
        p_player->y = mem_player_y-1;
        p_player->credits--;}
        break;
        case ACTION_MOVE_D: // modif
        if(p_player->credits>=1){
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
        p_player->credits--;}
        break;
        /******************************** DASH ***************************/
        case ACTION_DASH_L:
        if(p_player->credits>=10){
        for (i=0;i <8;i++)
        {    
            if (mem_player <= 0)
            {
                mem_player = MAP_SIZE - 1;
            }
            else{mem_player--;}
            world_paint_spot(mem_player, mem_player_y, id_player); 
        }
        p_player->x = mem_player;
        p_player->credits = p_player->credits - 10;}
        break;
        case ACTION_DASH_R :
        if(p_player->credits>=10){
        for (i=0;i <8;i++)
        {    
            if (mem_player >= MAP_SIZE)
            {
                mem_player = 0;
            }
            else{mem_player++;}
            world_paint_spot(mem_player, mem_player_y, id_player); 
        }
        p_player->x = mem_player;
        p_player->credits = p_player->credits - 10;}
        break;
        case ACTION_DASH_U:
        if(p_player->credits>=10){
        for (i=0;i <8;i++)
        {    
            if (mem_player_y <= 0) // Vérifie la limite haute de la carte
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
        p_player->credits = p_player->credits - 10;}
        break;
        case ACTION_DASH_D:
        if(p_player->credits>=10){
        for (i=0;i <8;i++)
        {    
            
            if (mem_player_y >= MAP_SIZE - 1)
            {
                mem_player_y = 0;
            }
            else{mem_player_y++;}
            world_paint_spot(mem_player, mem_player_y, id_player);
        }
        p_player->y = mem_player_y;
        p_player->credits = p_player->credits - 10;}
        break;
        /**************** TELEPORT ****************************/
        case ACTION_TELEPORT_L:
        if(p_player->credits>=2){
        if (mem_player < 8) // 
        {
            mem_player = 99 + (mem_player - 8);  // Téléportation dynamique
        }
        else
        {
            mem_player-=8;
        }
        world_paint_spot(mem_player, mem_player_y, id_player); 
        p_player->x = mem_player;
        p_player->credits = p_player->credits - 2;}
        break;
        case ACTION_TELEPORT_R:
        if(p_player->credits>=2){
        if (mem_player+8 >= MAP_SIZE-1)
        {
            mem_player = mem_player+8 - 99;
        }
        else
        {
            mem_player+=8;
        }
        world_paint_spot(mem_player, mem_player_y, id_player); 
        p_player->x = mem_player;
        p_player->credits = p_player->credits - 2;}
        break;
        case ACTION_TELEPORT_U:
        if(p_player->credits>=2){
        if ((int32_t)mem_player_y-8 < 0) // Vérifie la limite haute de la carte
        {
            mem_player_y = 99 + ((int32_t)mem_player_y-8) ; // Revient en bas si on dépasse la carte
        }
        else
        {
            mem_player_y = mem_player_y - 8; // Décrémente la position Y
        }
        world_paint_spot(mem_player, mem_player_y, id_player); 
        p_player->y = mem_player_y;
        p_player->credits = p_player->credits - 2;}
        break;
        case ACTION_TELEPORT_D:
        if(p_player->credits>=2){
        if (mem_player_y + 8 >= MAP_SIZE-1)
        {
            mem_player_y = (mem_player_y + 8) - 99;
        }
        else{mem_player_y+=8;}
        world_paint_spot(mem_player, mem_player_y, id_player); 
        p_player->y = mem_player_y;
        p_player->credits = p_player->credits - 2;}
        break;
        case ACTION_SPLASH:
        if(p_player->credits>=8){
        /* Parcours des colonnes autour du joueur*/
        for (int dx = -1; dx <= 1; dx++)  
        {
            for (int dy = -1; dy <= 1; dy++)  // Parcours des lignes autour du joueur
            {
                int new_x = (mem_player + dx + MAP_SIZE) % MAP_SIZE; 
                int new_y = (mem_player_y + dy + MAP_SIZE) % MAP_SIZE; 

                world_paint_spot(new_x, new_y, id_player); 
            }
        }
        p_player->credits -= 8; }// Réduction des crédits 
        break;
        case ACTION_BOMB:
        if(p_player->credits>=9){
        if (bomb_nbr < MAX_BOMBS) 
        {
            bombs[bomb_nbr].x = mem_player;
            bombs[bomb_nbr].y = mem_player_y;
            bombs[bomb_nbr].counter = 20; // 5 tours * 4 appels = 20
            bombs[bomb_nbr].player_id = id_player; // Stocker l'identifiant du joueur
            bomb_nbr++;
        }
        p_player->credits -= 9;}
        break;
        case ACTION_NUMBER:
        break;
    default:
        break;
    }
    for (i = 0; i < bomb_nbr; i++) {
        if (bombs[i].counter > 0) {
            bombs[i].counter--;
        }
        if (bombs[i].counter == 0) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int new_x = bombs[i].x + dx;
                    int new_y = bombs[i].y + dy;
                    if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE) {
                        world_paint_spot(new_x, new_y, bombs[i].player_id);
                    }
                }
            }
            // Déplace les bombes restantes pour combler le trou
            for (uint8_t j = i; j < bomb_nbr - 1; j++) {
                bombs[j] = bombs[j + 1];
            }
            bomb_nbr--;
            i--;
        }
    }
}

int32_t get_credit_player(t_player *p_player)
{
    return p_player->credits;
}
