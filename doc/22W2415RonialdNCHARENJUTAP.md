# TP - INF231_EC2 : Structures de Données II

## 📌 Description
Ce projet est un TP de **Structure de Données II** réalisé en C.  
Il contient plusieurs exercices fondamentaux (matrices, tableaux, vecteurs) organisés de façon **modulaire**.

Les fonctionnalités couvertes sont :
1. Somme de matrices
2. Produit de matrices
3. Recherche séquentielle dans un tableau
4. Multiplication `a × b` (par additions successives, récursive)
5. Test si un tableau est trié
6. Calcul de la médiane d’un tableau
7. Inversion d’un tableau
8. Produit vectoriel (en 3D)
9. Produit vecteur × matrice

---

## 📂 Organisation du projet
├── main.c # Programme principal avec menu
├── operations.c # Implémentation des fonctions
├── operations.h # Fichier d'en-tête (prototypes)
├── Makefile # Script de compilation
└── README.md # Documentation du projet

yaml
Copy code

---

## ⚙️ Compilation et exécution
### Avec `make` :
```bash
make        # Compile le projet
./tp        # Exécute le programme
make clean  # Supprime les fichiers objets et l'exécutable
Sans make (directement avec gcc) :
bash
Copy code
gcc main.c operations.c -o tp
./tp
📖 Utilisation
Au lancement, un menu interactif permet de choisir l’exercice à exécuter :

markdown
Copy code
==== MENU TP STRUCTURES DE DONNEES II ====
1. Somme de matrices
2. Produit de matrices
3. Recherche sequentielle
4. Multiplication a*b
5. Tester si tableau est trie
6. Mediane dans un tableau
7. Inverser un tableau
8. Produit vectoriel (3D)
9. Produit vecteur x matrice
0. Quitter
👨‍💻 Auteur
Nom : NCHARE Roniald 

Cours : INF231_EC2 - Structures de Données II

Enseignant responsable : PR. Metatagia

✨ Merci d’avoir consulté ce projet !





