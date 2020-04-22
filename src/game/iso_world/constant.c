/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** constant file
*/

#include "my_rpg.h"

const sfInt32 MS_UPDATE_PANEL = 100;

// MAP PARAMETERS
const char *DEFAULT_MAP_NAME = "undefined";
const char *MAP_EXTENSION = ".world";

const float MAP_SHADOW_SUM = 10.00f;
const float MAP_SHADOW_MUL = 00.1f;

const sfVector3f MAP_INIT_SAMP = {40, 40, 8};
const sfVector2f MAP_INIT_ANGL = {30, 25};
const sfVector2f MAP_INIT_ORIG = {1920 / 2, -200};
const sfColor MAP_LINE_COLOR = {255, 255, 255, 100};

const int EVT_MAP_TRANSLATE_DELTA = 10;
const float EVT_MAP_TRANSLATE_PERC = 0.1;
const float EVT_MAP_ROTATE_PERC = 0.03;
const int EVT_MAP_ROTATE_DELTA = 2;

const sfKeyCode KEY_MAP_TRANS_UP = sfKeyZ;
const sfKeyCode KEY_MAP_TRANS_DOWN = sfKeyS;
const sfKeyCode KEY_MAP_TRANS_LEFT = sfKeyQ;
const sfKeyCode KEY_MAP_TRANS_RIGHT = sfKeyD;

const sfKeyCode KEY_MAP_ROT_UP = sfKeyUp;
const sfKeyCode KEY_MAP_ROT_DOWN = sfKeyDown;
const sfKeyCode KEY_MAP_ROT_LEFT = sfKeyLeft;
const sfKeyCode KEY_MAP_ROT_RIGHT = sfKeyRight;

// Texture
const int TEXTURE_COUNT = 12;
const char *TEXTURE_PATH[] =
{
    "asset/sprite/iso_world/black.png",
    "asset/sprite/iso_world/dirt.png",
    "asset/sprite/iso_world/grass.png",
    "asset/sprite/iso_world/cobblestone.png",
    "asset/sprite/iso_world/stone.png",
    "asset/sprite/iso_world/snow.png",
    "asset/sprite/iso_world/water.png",
    "asset/sprite/iso_world/red.png",
    "asset/sprite/iso_world/real_black.png",
    "asset/sprite/iso_world/green.png",
    "asset/sprite/iso_world/blue.png",
    "asset/sprite/iso_world/sand.png"
};
const int TXTR_DIRT = 1;
const int TXTR_GRASS = 2;
const int TXTR_COBBLESTONE = 3;
const int TXTR_STONE = 4;
const int TXTR_SNOW = 5;
const int TXTR_WATER = 6;
const int TXTR_SAND = 11;
