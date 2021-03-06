/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** object
*/

#ifndef OBJ_T_H_
#define OBJ_T_H_

typedef struct object {
    int width;
    sfVector2f mtx_2d[2][2][2];
    sfVertexArray *vrtx_x[2][2][2];
    sfVertexArray *vrtx_y[2][2][2];
    sfVertexArray *vrtx_z[2][2][2];
    sfVertexArray *vrtx_txr[3];
    sfTexture *textures[3];
    const char **path_img;
    sfRenderStates render_state;
    sfVector3f size;
    sfVector3f size_txr;
    sfVector2f angle;
    sfVector2f origin;
    sfColor line_color;
    sfBool modified;
    sfVector2i coord_map;
    map_t *linked_map;
} object_t;

#endif
