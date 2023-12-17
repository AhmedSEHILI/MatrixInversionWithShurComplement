#ifndef __INVERSERMATRICE_H__
#define __INVERSERMATRICE_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<assert.h>
#include <time.h>



double** creerMatrice(uint64_t n);
double** lireMatrice(char *nomFichier);
void ecrireMatrice(char *nomFichier, double **matrice, uint64_t n);
void afficherMatrice(double** matrice, uint64_t n);
double** transposerMatrice(double** matrice, uint64_t n);
double** additionnerMatrices(double** matrice1, double** matrice2, uint64_t n);
double** soustraireMatrices(double** matrice1, double** matrice2, uint64_t n);
double** extraireMatrices(double** matrice, uint64_t n, uint8_t ordre);
void freeMatrice(double** matrice, uint64_t n);
uint8_t estPuissDeux(uint64_t n);
uint64_t trouverProchePuissDeux(uint64_t n);
double** ajusterMatrice(double** matrice, uint64_t n, uint64_t NouveauN);
double** recupererMatrice(double** matrice, uint64_t n);
double** strassenRecursive(double** matriceA, double** matriceB, uint64_t n);
double** multiplicationStrassen(double** matriceA, double** matriceB, uint64_t n);



/**********************************************************************************/

double** inverserMatDefPositive(double** matrice, uint64_t n);
double** inverserMatriceAvecStrassen(double** matrice, uint64_t n);


#endif
