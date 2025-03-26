#ifndef TAQUIN_H
#define TAQUIN_H

#define NB_COL 4
#define NB_LIG 4

typedef struct {
    int lig;
    int col;
} Carre;

typedef struct {
    Carre bloc[NB_LIG][NB_COL];
    int empty_x; // Position de la case vide (colonne)
    int empty_y; // Position de la case vide (ligne)
} Plateau;

/* Initialise le plateau : chaque case reçoit sa position de référence.
   La case vide est placée en bas à droite. */
void initialisationPlateau(Plateau* p);

/* Échange deux cases */
void swap(Carre* a, Carre* b);

/* Vérifie si la case (x, y) est adjacente à la case vide */
int is_valid_move(Plateau *p, int x, int y);

/* Déplace la case (x, y) vers la case vide si le mouvement est valide */
void move_tile(Plateau *p, int x, int y);

/* Mélange le plateau en effectuant un nombre donné de mouvements aléatoires */
void shuffle_plateau(Plateau *p, int moves);

/* Teste si le plateau est dans l'état final (chaque case est à sa position d’origine) */
int is_solved(Plateau *p);

#endif
