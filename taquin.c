#include <stdio.h>
#include <MLV/MLV_all.h>

#define NB_COL 4
#define NB_LIG 4

typedef struct carre{
    int lig;
    int col;
}Carre;

typedef struct plateau{
    Carre bloc[NB_COL][NB_LIG];
}Plateau;

void InitialisationPlateau(Plateau* P){
    int i,j;
    for(i=0;i<NB_LIG;i++){
        for(j=0;j<NB_COL;j++){
            ((P->bloc)[i][j]).lig=i;
            ((P->bloc)[i][j]).col=j;
        }
    }
}