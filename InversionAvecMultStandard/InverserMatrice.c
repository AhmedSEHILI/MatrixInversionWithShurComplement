#include"InverserMatrice.h"


/*** fonction de création d'une matrice carrée de taille n*n ***/
double** creerMatrice(uint64_t n){

    uint64_t i;

    double** matrice = (double **)malloc(n*sizeof(double*));  // ! sizeof *double !
    for(i = 0; i<n; i++){
        matrice[i] = (double*)calloc(n,sizeof(double)); //test
    }
     
return matrice;
}

/*** fonction de création de chargement d'une matrice à partir d'un fichier .txt ***/

double** lireMatrice(char *nomFichier){

    FILE* Fichier = fopen(nomFichier, "r");

    if (Fichier == NULL) {
        assert(0);
    }
    
    uint64_t n, i, j;

    double valeur;

    fscanf(Fichier, "%ld", &n);  // chargement de n: la taille de chaque ligne (colonne) de la matrice
    
    double** matrice = creerMatrice(n);
    
    for(i = 0; i< n; i++) {

        for(j = 0; j< n; j++){

            fscanf(Fichier, "%lf", &valeur); 
            matrice[i][j] = valeur;
            
        }
    }  
    fclose(Fichier);
    return matrice;
}



/*** fonction d'écriture d'une matrice dans un fichier .txt ***/


void ecrireMatrice(char *nomFichier, double **matrice, uint64_t n) {

    uint64_t i, j;

    FILE *fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fprintf(fichier, "%lf ", matrice[i][j]);
        }
        fprintf(fichier, "\n");
    }

    fclose(fichier);
}



/*** fonction d'affichage d'une matrice ***/


void afficherMatrice(double** matrice, uint64_t n){

    uint64_t i, j;

    for(i = 0; i< n; i++) {
          
        for(j = 0; j< n; j++){

            printf("%lf | ", matrice[i][j]);
        }
        printf("\n");
    }

}




/*** fonction (naive) de multiplication de deux matrice de taille n*n chacune, de compléxité O(n³) ***/

double** multiplicationStandard(double** matrice1, double** matrice2, uint64_t n){

    
    uint64_t i, j, k;
    double** resultat= creerMatrice(n);


    for(i = 0; i< n; i++) {

        for(j = 0; j< n; j++){

             for(k = 0; k< n; k++){

                    resultat[i][j] += matrice1[i][k] * matrice2[k][j];                 

             }
            
        }
    }     


return resultat;
}



/*** fonction de transposition d'une matrice carrée de taille n*n ***/

double** transposerMatrice(double** matrice, uint64_t n){

    uint64_t i, j;

    double** resultat= creerMatrice(n);

    for(i = 0; i< n; i++) {

        for(j = 0; j< n; j++){

            
            resultat[i][j] = matrice[j][i];
            
        }
    } 
    
return resultat;
}


/*** fonction d'adition de deux matrices de taille n*n chacune ***/

double** additionnerMatrices(double** matrice1, double** matrice2, uint64_t n){

    uint64_t i, j;    

    double** resultat= creerMatrice(n);
    for(i = 0; i< n; i++) {

        for(j = 0; j< n; j++){

            resultat[i][j] = matrice1[i][j]+matrice2[i][j];
            
        }
    } 
return resultat;
}





/*** fonction de soustraction de deux matrices de taille n*n chacune ***/

double** soustraireMatrices(double** matrice1, double** matrice2, uint64_t n){

    uint64_t i, j;    

    double** resultat= creerMatrice(n);
    for(i = 0; i< n; i++) {

        for(j = 0; j< n; j++){

            resultat[i][j] = matrice1[i][j]-matrice2[i][j];
            
        }
    } 
return resultat;
}

/*** fonction d'extraction de la matrice d'ordre "ordre" de taille (n/2)*(n/2) à partir d'une matrice de taille n*n ***/

double** extraireMatrices(double** matrice, uint64_t n, uint8_t ordre){

    uint64_t i, j;    

    double** resultat= creerMatrice(n/2);

        if(ordre == 1) {

            for(i = 0; i< n/2; i++) {

                for(j = 0; j< n/2; j++){

                    resultat[i][j] = matrice[i][j];
                    
                }
            }
        }
        else if (ordre == 2){

            for(i = 0; i< n/2; i++) {

                for(j = n/2; j< n; j++){

                    resultat[i][j-(n/2)] = matrice[i][j];
                    
                }
            }
        }
        else if (ordre == 3) {

            for(i = n/2; i< n; i++) {

                for(j = 0; j< n/2; j++){

                    resultat[i-(n/2)][j] = matrice[i][j];
                    
                }
            }
        }
        else if (ordre == 4) {

            for(i = n/2; i< n; i++) {

                for(j = n/2; j< n; j++){

                    resultat[i-(n/2)][j-(n/2)] = matrice[i][j];
                    
                }
            }
        }

        else printf("une erreur est survenue");

    
return resultat;
}


/*** fonction de libération d'une matrice carrée de taille n*n ***/

void freeMatrice(double** matrice, uint64_t n){

    uint64_t i;

    
    for(i = 0; i<n; i++){
        free(matrice[i]);
    }
    free(matrice);
     
}


/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/



/*** fonction d'inversion d'une matrice définie positive de taille n*n ***/

double** inverserMatDefPositive(double** matrice, uint64_t n){

    uint64_t i, j;

    double** B = creerMatrice(n/2);
    double** C = creerMatrice(n/2);
    double** CT = creerMatrice(n/2);
    double** D = creerMatrice(n/2);

    double** Binv = creerMatrice(n/2);
    
    double** CBinv = creerMatrice(n/2);

    double** BinvCT = creerMatrice(n/2);

    double** S = creerMatrice(n/2);
    double** Sinv = creerMatrice(n/2);

    double** SinvCBinv = creerMatrice(n/2);
    
    double** BinvCTSinv = creerMatrice(n/2);

    double** BinvCTSinvCBinv = creerMatrice(n/2);

    double** BinvplusBinvCTSinvCBinv = creerMatrice(n/2);

    int64_t N = n/2;
    
    B = extraireMatrices(matrice, n, 1);
    CT = extraireMatrices(matrice, n, 2);
    C = extraireMatrices(matrice, n, 3);
    D = extraireMatrices(matrice, n, 4);    

    if ( N == 1){
               
        if(B[0][0]<=0){
            printf("Erreur, Cette matrice et singulière, elle n'a pas d'inverse\n");
            assert(0);
        }
     

        Binv[0][0] =  1/B[0][0];


        CBinv = multiplicationStandard(C, Binv, N);
        BinvCT = transposerMatrice(CBinv, N);

        S = soustraireMatrices(D, multiplicationStandard(C, BinvCT, N), N);

        if(S[0][0] <= 0){
            printf("Erreur, Cette matrice et singulière, elle n'a pas d'inverse\n");
            assert(0);
        }

        Sinv[0][0]=1/S[0][0];



        SinvCBinv = multiplicationStandard(Sinv, CBinv, N);

        BinvCTSinv = transposerMatrice(SinvCBinv, N);

        BinvCTSinvCBinv = multiplicationStandard(BinvCTSinv, CBinv, N);

        BinvplusBinvCTSinvCBinv = additionnerMatrices(Binv, BinvCTSinvCBinv, N);

        double** resultat= creerMatrice(2*N);
        
        for(i = 0; i<N; i++){

            for(j = 0; j<N; j++){

                resultat[i][j] = BinvplusBinvCTSinvCBinv[i][j];
                resultat[i][j+N] = (-1)*BinvCTSinv[i][j];
                resultat[i+N][j] = (-1)*SinvCBinv[i][j];
                resultat[i+N][j+N] = Sinv[i][j];
            }

        }
    
    return resultat;
        
    }


        Binv = inverserMatDefPositive(B, N);  

        CBinv = multiplicationStandard(C, Binv, N);

        BinvCT = transposerMatrice(CBinv, N);

        S = soustraireMatrices(D, multiplicationStandard(C, BinvCT, N), N);

        Sinv = inverserMatDefPositive(S, N);   

        SinvCBinv = multiplicationStandard(Sinv, CBinv, N);

        BinvCTSinv = transposerMatrice(SinvCBinv, N);

        BinvCTSinvCBinv = multiplicationStandard(BinvCTSinv, CBinv, N);

        BinvplusBinvCTSinvCBinv = additionnerMatrices(Binv, BinvCTSinvCBinv, N);
   



        double** resultat= creerMatrice(2*N);
        
        for(i = 0; i<N; i++){

            for(j = 0; j<N; j++){

                resultat[i][j] = BinvplusBinvCTSinvCBinv[i][j];
                resultat[i][j+N] = (-1)*BinvCTSinv[i][j];
                resultat[i+N][j] = (-1)*SinvCBinv[i][j];
                resultat[i+N][j+N] = Sinv[i][j];
            }

        }


        freeMatrice(B, N);
        freeMatrice(C, N);
        freeMatrice(CT, N);
        freeMatrice(D, N);
        freeMatrice(Binv, N);
        freeMatrice(CBinv, N);
        freeMatrice(BinvCT, N);
        freeMatrice(S, N);
        freeMatrice(Sinv, N);
        freeMatrice(SinvCBinv, N);
        freeMatrice(BinvCTSinv, N);
        freeMatrice(BinvCTSinvCBinv, N);
        freeMatrice(BinvplusBinvCTSinvCBinv, N);


return resultat;
}


/************************************************************************/


/*** fonction d'inversion d'une matrice inversible de taille quelconque***/

double** inverserMatrice(double** matrice, uint64_t n){

    double** matriceINV = creerMatrice(n);    
    double** matriceT = creerMatrice(n);
    
    matriceT = transposerMatrice(matrice, n);

    matriceINV = multiplicationStandard(inverserMatDefPositive(multiplicationStandard(matriceT, matrice, n), n), matriceT, n);


return matriceINV;
}


