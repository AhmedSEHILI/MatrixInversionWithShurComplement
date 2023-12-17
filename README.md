# Inversion de matrices

Ce répertoire contient un code C optimisé pour l'inversion de matrices, basé sur le complément de Schur. La complexité de ce programme est de l'ordre O(n³) si les multiplications matricielles au sein du programme sont standard, et de l'ordre O(n^2.81) si les multiplications matricielles sont de Strassen. Le code implémente l'inversion avec les deux méthodes de multiplication. Compilation


## Compilation
```bash
gcc -Wall main.c InverserMatrice.c -o main
```
## Exécution

Le programme prend deux arguments en ligne de commande :  
* Le nom du fichier .txt en entrée qui contient une matrice (la première ligne du fichier contient n)
* Le nom du fichier .txt en sortie qui va contenir la matrice inversée

Utilisez la commande suivante  pour l'éxécution:
```bash
./main matriceN.txt sortieN.txt
```
Le temps d'exécution en secondes sera affiché à la fin du programme. 

## Génération des matrices

Un script Python  est fourni pour générer des matrices carrées 'inversibles' aléatoirement. Utilisez le script de la manière suivante :
```bash
python3 generateurMatriceInversible.py matriceN.txt n
```
**IMPORTANT** Ce script utilise la bibliothèque NumPy de Python, qui doit être installée avant l'utilisation. Pour plus d'informations sur l'installation de NumPy, consultez numpy.org/install: [https://numpy.org/install/](https://numpy.org/install/). 

## Tests numériques

Chaque dossier contient des matrices déjà générées qui sont prêtes pour les tests. Les résultats des tests sont enregistrés dans des fichiers avec le modèle de nom suivant : sortieN.txt.

## Exemple de compilation et d'exécution
```bash
python3 generateurMatriceInversible.py matrice64.txt 
gcc -Wall main.c InverserMatrice.c -o main 
./main matrice64.txt sortie64.txt
```
**Attention:** La commande système à la fin du fichier main ouvrira le fichier sortieN.txt directement, elle fonctionne uniquement sur Linux. Si vous utilisez un autre OS, désactivez-la.  


<small>Ce code est fourni par Ahmed SEHILI dans un cadre pédagogique.</small>

