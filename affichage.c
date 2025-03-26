#include <stdio.h>
#include <MLV/MLV_all.h>
#include <affichage.h>

void print_taquin(Plateau* P)){
    int width=512;
    int length=512;
    MLV_free_window();
    MLV_create_window("taquin",NULL,width,length);
    //MLV_load_image(const char *file_image);
    int x=width/NB_COL;
    int y=length/NB_LIG;







    MLV_actualise_window();
    MLV_free_window();
}
