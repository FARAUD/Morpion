#include <stdio.h>
#define N 9

void afficher_regles (void)
{
    printf (" ********** Bienvenue sur le jeu de Morpion ********** \n");
    printf (" Vous jouez tour a tour soit des O, soit des X.\n");
    printf (" Le premier qui gagne est celui qui arrive a aligner 5 signes en ligne, en colonne ou en diagonale.\n");
    printf (" ****************     Bonne chance    **************** \n");
    printf ("\n");
}


char remplir_grille (char grille[N][N+1]) {
    int i, j;

    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            grille[i][j]='-';
        }
        grille[i][j+1]='\0';
    }

    return grille;
}

void afficher_grille (char grille[N][N+1]) {
    int i,j;

    printf("     ");
    for (i=0;i<N;i++){    //affiche le numero des colonnes bien aligné aux colonnes
        if (i < 10)
            printf (" %i ", i+1);
        else
            printf ("%i ", i+1);
    }

    printf("\n    ");
    for (i=0;i<3*N+2;i++){   //affiche grille du dessus
        printf ("-");
     }

    for (i=0;i<N;i++){
        printf("\n");
        if (i<9)
            printf(" ");

        printf(" %d |",i+1);     //affiche grille du cote gauche
        for (j=0;j<N;j++){
                printf(" %c ",grille[i][j]);    //affiche la grille
        }
        printf("|");   //affiche grille du cote droit
    }
    printf("\n");
    printf("    ");
    for (i=0;i<3*N+2;i++){
        printf ("-");      //affiche grille du dessous
    }
}

void jeu (char grille[N][N+1]) {
    int i,j;
    int k=2;    //Pour utiliser le modulo (%)

    printf ("\n Vous allez devoir entrer le numero de ligne puis le numero de colonne.\n");
    printf(" Le premier joueur a les X.\n");

    while (test (grille))
    {
        printf ("\n Ou voulez vouz jouer ? : ");
        scanf ("%d %d",&i,&j); 
        if (grille[i-1][j-1]=='-' && i<=N && j<=N)
        {
            if (k%2==0){
                grille[i-1][j-1]='X';  //Le premier joueur prend les X
            }
            else{
                grille[i-1][j-1]='O';
            }
            k=k+1;
            afficher_grille (grille);
        }
        else
            printf("\n Vous ne pouvez pas jouer ici.\n");
    }
}

void test(char grille[N][N+1])
{
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            if (grille [i][j]=='-'){
                return 1;
            }
        }
    }
    printf ("\n Toutes les cases sont occupees.\n");
    return 0;
}


int main (void) {
    char grille[N][N+1];   //N+1 sert a mettre \0 a la fin des chars

    afficher_regles();

    remplir_grille(grille);
    afficher_grille(grille);
    jeu(grille);

    free(grille);
    return 0;
}
