#include <stdio.h>
#include <MLV/MLV_all.h>
#include "taquin.h"
#include "affichage.h"

int main(int argc, char* argv[]){
    if(argc < 2) {
        fprintf(stderr, "Usage: %s image_file\n", argv[0]);
        return 1;
    }

    /* Création de la fenêtre et initialisation de la LibMLV */
    MLV_create_window("Jeu de Taquin", "Taquin", 512, 512);

    MLV_Image* image = MLV_load_image(argv[1]);
    if(image == NULL) {
        fprintf(stderr, "Erreur de chargement de l'image %s\n", argv[1]);
        return 1;
    }

    /* Initialisation et mélange du plateau */
    Plateau plateau;
    initialisationPlateau(&plateau);
    shuffle_plateau(&plateau, 120);

    /* Affichage initial du plateau */
    afficher_plateau(&plateau, image);

    int x, y;
    int tile_width = 512 / NB_COL;
    int tile_height = 512 / NB_LIG;

    /* Boucle de jeu */
    while(!is_solved(&plateau)) {
        MLV_wait_mouse(&x, &y);
        int grid_x = x / tile_width;
        int grid_y = y / tile_height;
        if(is_valid_move(&plateau, grid_x, grid_y)) {
            move_tile(&plateau, grid_x, grid_y);
            afficher_plateau(&plateau, image);
        }
    }

    /* Affichage du message de victoire */
    MLV_draw_text(170, 260, "Bravo! Vous avez gagne!", MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(3);

    MLV_free_window();
    return 0;
}
