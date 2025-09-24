#include <stdio.h>
#include <stdlib.h>


void afficherTableau(int T[], int n) {
    for(int i=0;i<n;i++) printf("%d ",T[i]);
    printf("\n");
}

void afficherMatrice(int **M, int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",M[i][j]);
        printf("\n");
    }
}

int* saisirTableau(int n) {
    int *T = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", &T[i]);
    return T;
}

int** saisirMatrice(int n, int m) {
    int **M = malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        M[i] = malloc(m * sizeof(int));
        for(int j=0;j<m;j++) scanf("%d", &M[i][j]);
    }
    return M;
}

int** allouerMatrice(int n, int m) {
    int **M = malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        M[i] = calloc(m, sizeof(int));
    }
    return M;
}

void libererMatrice(int **M, int n) {
    for(int i=0;i<n;i++) free(M[i]);
    free(M);
}

void sommeMatrices(int **A, int **B, int **C, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void produitMatrices(int **A, int **B, int **C, int n, int p, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int rechercheSeq(int T[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (T[i] == x) return i;
    return -1;
}

int multAvecPlusUn(int a, int b) {
    int res = 0;
    int signe = (b < 0) ? -1 : 1;
    for (int i = 0; i < abs(b); i++)
        res += a;
    return res * signe;
}


int estTrie(int T[], int n) {
    for (int i = 1; i < n; i++)
        if (T[i] < T[i-1]) return 0;
    return 1;
}


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double mediane(int T[], int n) {
    int *copy = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) copy[i]=T[i];
    qsort(copy, n, sizeof(int), compare);
    double med = (n % 2) ? copy[n/2] : (copy[n/2 - 1] + copy[n/2]) / 2.0;
    free(copy);
    return med;
}

void inverser(int T[], int n) {
    for (int i = 0, j = n-1; i < j; i++, j--) {
        int tmp = T[i]; T[i] = T[j]; T[j] = tmp;
    }
}

void produitVectoriel(int u[3], int v[3], int res[3]) {
    res[0] = u[1]*v[2] - u[2]*v[1];
    res[1] = u[2]*v[0] - u[0]*v[2];
    res[2] = u[0]*v[1] - u[1]*v[0];
}

void vecteurFoisMatrice(int v[], int **M, int res[], int m, int n) {
    for (int j = 0; j < n; j++) {
        res[j] = 0;
        for (int i = 0; i < m; i++)
            res[j] += v[i] * M[i][j];
    }
}

int main() {
    int choix;
    do {
        printf("\n--- TP STRUCTURE DE DONNEES II ---\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche séquentielle dans un tableau\n");
        printf("4. a * b (exclusivement +1)\n");
        printf("5. Tester si un tableau est trie\n");
        printf("6. Médiane d'un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Produit vecteur x matrice\n");
        printf("0. Quitter\n");
        printf("Choisir une option: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: {
                int n,m;
                printf("Entrez le nombre de  lignes et  de colonnes: ");
                scanf("%d %d",&n,&m);
                printf("Super!créons maintenant les matrices A et B à sommé:");
                 printf("\n");
                printf("Commençons par  la matrice A");
                int **A = saisirMatrice(n,m);

                printf("Maintenant  la matrice B");

                int **B = saisirMatrice(n,m);
                int **C = allouerMatrice(n,m);
                sommeMatrices(A,B,C,n,m);
                printf(" La Somme des matrices A et B est :\n"); afficherMatrice(C,n,m);
                libererMatrice(A,n); libererMatrice(B,n); libererMatrice(C,n);
                break;
            }
            case 2: {
                int n,p,m;
                printf("Entre les dimensions de A (n p): ");
                scanf("%d %d",&n,&p);
                printf("Entre les dimensions B (p m): ");
                int p2; scanf("%d %d",&p2,&m);
                if(p!=p2){ printf("Dimensions incompatibles!\n"); break; }
                printf("Super!créons maintenant les matrices A et B à multiplier:");
                printf("\n");
                printf("Saisi la matrice A");
                int **A = saisirMatrice(n,p);
                printf("Saisi la matrice B");
                int **B = saisirMatrice(p,m);
                int **C = allouerMatrice(n,m);
                produitMatrices(A,B,C,n,p,m);
                printf(" le Produit de A*B est:\n"); afficherMatrice(C,n,m);
                libererMatrice(A,n); libererMatrice(B,p); libererMatrice(C,n);
                break;
            }
            case 3: {
                int n; printf("Hello! Entrer la taille tableau svp: "); scanf("%d",&n);
                 printf("Super!créons maintenant notre tableau:");
                int *T = saisirTableau(n);
                int x; printf("Entre la valeur a rechercher: "); scanf("%d",&x);
                int idx = rechercheSeq(T,n,x);
                if(idx==-1) printf("Dommage!Valeur non trouvée\n");
                else printf("Bravo! valeur recherché se Trouve a l'indice %d\n",idx);
                free(T);
                break;
            }
            case 4: {
                int a,b;
                printf("Entrez les valeurs de A et B: "); scanf("%d %d",&a,&b);
                printf("Resultat: %d\n", multAvecPlusUn(a,b));
                break;
            }
            case 5: {
                int n; printf("Hello! Entrer la taille tableau svp: "); scanf("%d",&n);
                printf("Super!créons maintenant notre tableau:");
                int *T = saisirTableau(n);
                printf(estTrie(T,n) ? "Youpiii! Le tableau est trié\n" : "Dommage!Le tableau n'est pas trié\n");
                free(T);
                break;
            }
            case 6: {
                int n; printf("Hello! Entrer la taille tableau svp: "); 
                scanf("%d",&n);
                printf("Super!créons maintenant notre tableau:");
                int *T = saisirTableau(n);
                printf("La Mediane de notre tableau est : %.2lf\n", mediane(T,n));
                free(T);
                break;
            }
            case 7: {
                int n; printf(" Hello! Entre la taille tableau stp:");
                scanf("%d",&n);
                 printf("Super!créons maintenant notre tableau:");
                int *T = saisirTableau(n);
                inverser(T,n);
                printf("Au final le tableau inversé est : "); afficherTableau(T,n);
                free(T);
                break;
            }
            case 8: {
                int u[3],v[3],res[3];
                printf(" Entrer les elements du vecteur u (3 elements): "); for(int i=0;i<3;i++) scanf("%d",&u[i]);
                printf(" Entrer les elements du vecteur v (3 elements): "); for(int i=0;i<3;i++) scanf("%d",&v[i]);
                produitVectoriel(u,v,res);
                printf("le Produit vectoriel de u*v est : (%d,%d,%d)\n",res[0],res[1],res[2]);
                break;
            }
            case 9: {
                int m,n;
                printf("Entre la taille du vecteur (m) et nombres de  colonnes de la  matrice (n): ");
                scanf("%d %d",&m,&n);
                 printf("Super!créons maintenant notre vecteur:");
                int *v = saisirTableau(m);
                printf("Saisi la matrice n");
                int **M = saisirMatrice(m,n);
                int *res = malloc(n * sizeof(int));
                vecteurFoisMatrice(v,M,res,m,n);
                printf("le resultat est : "); afficherTableau(res,n);
                free(v); free(res); libererMatrice(M,m);
                break;
            }
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide\n");
        }
    } while(choix != 0);

    return 0;
}
