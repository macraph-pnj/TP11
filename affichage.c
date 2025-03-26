#include "affichage.h"

void afficher_plateau(Plateau* p, MLV_Image* image) {
    int i, j;
    int tile_width = 512 / NB_COL;
    int tile_height = 512 / NB_LIG;
    for(i = 0; i < NB_LIG; i++){
        for(j = 0; j < NB_COL; j++){
            if(j == p->empty_x && i == p->empty_y) {
                MLV_draw_filled_rectangle(j * tile_width, i * tile_height, tile_width, tile_height, MLV_COLOR_BLACK);
            } else {
                int source_x = p->bloc[i][j].col * tile_width;
                int source_y = p->bloc[i][j].lig * tile_height;
                MLV_draw_partial_image(image, source_x, source_y,tile_width,tile_height, j*tile_width,i *tile_height);
        }
    }
    MLV_actualise_window();
    }
}
