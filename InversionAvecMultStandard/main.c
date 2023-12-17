#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<assert.h>
#include <time.h>
#include"InverserMatrice.h"


int main(int argc, char** argv){

    if(argc != 3){
    
        printf("Le nombre d'arguments en entré est faux\n");
        return EXIT_FAILURE;
    }    

    time_t debutTemps, finTemps;
    time(&debutTemps);          /*** utilisé pour mesurer le temps d'éxécution d'un programme ***/

    FILE* F = fopen(argv[1], "r");

    if (F == NULL) {
        assert(0);
    }
    
    uint64_t n;

    fscanf(F, "%ld", &n);
    rewind(F);
    
    
    double **matrice = creerMatrice(n);


    
    
    matrice= lireMatrice(argv[1]);     // récupérer la matrice à partir du fichier en entrée


    matrice = inverserMatrice(matrice, n);  // inverser la matrice


    ecrireMatrice(argv[2], matrice, n);   // écrire la matrice dans un fichier de sortie
 


    freeMatrice(matrice,n);     // libération de la matrice

    time(&finTemps);

    double tempsdeProgramme =  difftime(finTemps, debutTemps);

    printf("Ce programme d'inversion de matrice a pris %f secondes pour s'exécuter.\n", tempsdeProgramme); // affichage du temps d'éxécution du programme

    char commande[100];
    sprintf(commande, "xdg-open %s", argv[2]);
    system(commande); // ouverture du fichier résultat

return EXIT_SUCCESS;
}
