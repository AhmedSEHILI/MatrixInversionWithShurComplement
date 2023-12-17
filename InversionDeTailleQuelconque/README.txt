Pour réaliser l'inversion d'une matrice de taille n*n avec n qui n'est pas une puissance de 2;
on peut chercher la puissance de 2 supérieure la plus proche de n;
ensuite, on étend la matrice n*n de telle sorte qu'elle soit de taille 2^k * 2^k, tout en ajoutant des 1 sur la diagonale, et des 0 ailleurs.
Enfin on applique l'inversion sur cette matrice 2^k * 2^k, et on récupère la matrice n * n (taille originale)
