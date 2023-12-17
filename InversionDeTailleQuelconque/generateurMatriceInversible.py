import numpy as np
import sys

def genererMatriceInversible(taille):
    # Genere une matrice 'naturelle' aléatoire entre 1 et 10
    matrice = np.random.randint(1, 10, size=(taille, taille))  

    # Verifie si la matrice est inversible sinon regenerer
    while np.linalg.matrix_rank(matrice) < taille:
        matrice = np.random.randint(1, 10, taille=(taille, taille))

    return matrice

#ecrire une matrice dans un fichier .txt
def ecrireMatrice(matrice, nomFichier):  
    with open(nomFichier, 'w') as file:
        # ecrire la taille de chaque ligne dans la premiere ligne
        file.write(f"{matrice.shape[0]}\n")

        # ecrire la matrice dans les lignes qui suivent
        np.savetxt(file, matrice, fmt="%d", delimiter=" ")

# Vérifier si la taille de la matrice est rentrée en ligne de commande
if len(sys.argv) != 3:
    print("nombre d'arguments érroné")
    sys.exit(1)

# Recuperer la taille de la matrice et le nom de fichier de sortie depuis la ligne de commande
taille = int(sys.argv[2])
nomFichier = sys.argv[1]


# Générer et sauvegarder la matrice inversible naturelle
matriceInversible = genererMatriceInversible(taille)
ecrireMatrice(matriceInversible, nomFichier)

