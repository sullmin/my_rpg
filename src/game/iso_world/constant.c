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

const sfVector3f MAP_INIT_SAMP = {32, 32, 5};
const sfVector2f MAP_INIT_ANGL = {45, 35};
const sfVector2f MAP_INIT_ORIG = {1920 / 2, 0};
const int MAP_INIT_HEIGHT = 50;
const int MAP_INIT_WIDTH = 50;
const sfColor MAP_LINE_COLOR = {255, 255, 255, 255};

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
    "asset/img/black.png",
    "asset/img/dirt.png",
    "asset/img/grass.png",
    "asset/img/cobblestone.png",
    "asset/img/stone.png",
    "asset/img/snow.png",
    "asset/img/water.png",
    "asset/img/red.png",
    "asset/img/real_black.png",
    "asset/img/green.png",
    "asset/img/blue.png",
    "asset/img/sand.png"
};
const int TXTR_DIRT = 1;
const int TXTR_GRASS = 2;
const int TXTR_COBBLESTONE = 3;
const int TXTR_STONE = 4;
const int TXTR_SNOW = 5;
const int TXTR_WATER = 6;
const int TXTR_SAND = 11;
