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


/************************************************************************/


/*** fonction de vérification si un nombre est une puissance de deux ***/

uint8_t estPuissDeux(uint64_t n){ 
    
    return (n > 0) && ((n & (n - 1)) == 0); 

}


/*** fonction pour retourner la plus proche puissance de deux supérieur d'un nombre donné ***/

uint64_t trouverProchePuissDeux(uint64_t n){ 
    
    while(!estPuissDeux(n)){
        n++;
    }
return n;
}


/*** fonction d'ajustasion d'une matrice de taille n*n pour qu'elle soit de taille (2^k)*(2^k) ***/

double** ajusterMatrice(double** matrice, uint64_t n, uint64_t NouveauN){
    
    uint64_t i;
    matrice = (double**)realloc(matrice, NouveauN*sizeof(double));    
    for(i = 0; i<NouveauN; i++){
        matrice[i] = (double*)realloc(matrice[i], NouveauN*sizeof(double));   
    }


    for(i = n; i<NouveauN; i++){   
        matrice[i][i] = 1;
    }
    
return matrice;
}


/*** fonction d'extraction d'une matrice n*n à partir d'une matrice de taille (2^k)*(2^k)  [n<2^k]***/

double** recupererMatrice(double** matrice, uint64_t n){
    
    uint64_t i;
    matrice = (double**)realloc(matrice, n*sizeof(double));    
    for(i = 0; i<n; i++){
        matrice[i] = (double*)realloc(matrice[i], n*sizeof(double));   
    }
    
return matrice;
}


/************************************************************************/


/************************************************************************/
/************************************************************************/
/**************************** Strassen **********************************/
/************************************************************************/
/************************************************************************/

/*** fonction de multiplication de deux matrice de taille 2^k*2^k chacune à l'aide de l'algorithme de strassen ***/

double** strassenRecursive(double** matriceA, double** matriceB, uint64_t n){

        uint64_t i, j;
        double** resultat = creerMatrice(n);

    if(n>1){
        double** A11 = extraireMatrices(matriceA, n, 1);
        double** A12 = extraireMatrices(matriceA, n, 2);
        double** A21 = extraireMatrices(matriceA, n, 3);
        double** A22 = extraireMatrices(matriceA, n, 4);

        double** B11 = extraireMatrices(matriceB, n, 1);
        double** B12 = extraireMatrices(matriceB, n, 2);
        double** B21 = extraireMatrices(matriceB, n, 3);
        double** B22 = extraireMatrices(matriceB, n, 4);
        
        
        double** m1= strassenRecursive(additionnerMatrices(A11,A22,n/2),additionnerMatrices(B11,B22,n/2),n/2);
		double** m2= strassenRecursive(additionnerMatrices(A21,A22,n/2),B11,n/2);
		double** m3= strassenRecursive(A11,soustraireMatrices(B12,B22,n/2),n/2);
		double** m4= strassenRecursive(A22,soustraireMatrices(B21,B11,n/2),n/2);
		double** m5= strassenRecursive(additionnerMatrices(A11,A12,n/2),B22,n/2);
		double** m6= strassenRecursive(soustraireMatrices(A21,A11,n/2),additionnerMatrices(B11,B12,n/2),n/2);
		double** m7= strassenRecursive(soustraireMatrices(A12,A22,n/2),additionnerMatrices(B21,B22,n/2),n/2);

		double** R11 = additionnerMatrices(soustraireMatrices(additionnerMatrices(m1,m4,n/2),m5,n/2),m7,n/2);
		double** R12 = additionnerMatrices(m3,m5,n/2);
		double** R21 = additionnerMatrices(m2,m4,n/2);
		double** R22 = additionnerMatrices(soustraireMatrices(additionnerMatrices(m1,m3,n/2),m2,n/2),m6,n/2);

        

        for(i = 0; i<n/2; i++){

            for(j = 0; j<n/2; j++){

                resultat[i][j] = R11[i][j];
                resultat[i][j+n/2] = R12[i][j];
                resultat[i+n/2][j] = R21[i][j];
                resultat[i+n/2][j+n/2] = R22[i][j];
            }

        }

            freeMatrice(A11, n/2);
            freeMatrice(A12, n/2);
            freeMatrice(A21, n/2);
            freeMatrice(A22, n/2);

            freeMatrice(B11, n/2);
            freeMatrice(B12, n/2);
            freeMatrice(B21, n/2);
            freeMatrice(B22, n/2);

            freeMatrice(m1, n/2);
            freeMatrice(m2, n/2);
            freeMatrice(m3, n/2);
            freeMatrice(m4, n/2);
            freeMatrice(m5, n/2);
            freeMatrice(m6, n/2);
            freeMatrice(m7, n/2);

            freeMatrice(R11, n/2);
            freeMatrice(R12, n/2);
            freeMatrice(R21, n/2);
            freeMatrice(R22, n/2);

    }

    else {

		resultat[0][0]=matriceA[0][0]*matriceB[0][0];
	}
    


return resultat;
}

/*** fonction de multiplication de deux matrice de taille n*n (n quelconque) chacune à l'aide de l'algorithme de strassen ***/

double** multiplicationStrassen(double** matriceA, double** matriceB, uint64_t n){

    

    double** resultat = creerMatrice(n);

    uint64_t N = n;
    int8_t ajustée = 0;

    if(!estPuissDeux(n)){
        n = trouverProchePuissDeux(n);
        matriceA = ajusterMatrice(matriceA, N, n);
        matriceB = ajusterMatrice(matriceB, N, n);
        ajustée = 1;
    }
    resultat = strassenRecursive(matriceA, matriceB, n);
    
    if(ajustée){
        resultat = recupererMatrice(resultat, N);
    }

return resultat;
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

double** inverserMatriceQuelconque(double** matrice, uint64_t n){

    double** matriceINV = creerMatrice(n);    
    double** matriceT = creerMatrice(n);
    
    uint64_t N = n;
    uint8_t ajustée = 0;

    if(!estPuissDeux(n)){
        n = trouverProchePuissDeux(n);
        matrice = ajusterMatrice(matrice, N, n);
        ajustée = 1;
    }
    
    matriceT = transposerMatrice(matrice, n);

    matriceINV = multiplicationStandard(inverserMatDefPositive(multiplicationStandard(matriceT, matrice, n), n), matriceT, n);

    if(ajustée){
        matriceINV = recupererMatrice(matriceINV, N);
    }

return matriceINV;
}


