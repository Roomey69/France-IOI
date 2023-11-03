#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// FONCTIONNEL

int intinput(char phrase[]){
    int x;
    printf("%s",phrase);scanf("%d",&x);
    return x;
}

void charinput(char phrase[],char *mot){
    printf("%s",phrase);scanf(" %s", mot);
}

void combinations_recursive(int x, int n, int* combinaison, int index, char* mot) {
    if (index == n) {     
        for (int i = 0; i < n; i++) {
            printf(" %c", mot[combinaison[i]]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < x; i++) {
        combinaison[index] = i;
        combinations_recursive(x, n, combinaison, index + 1, mot);
    }
}

void generate_combinations(int x, int n, char* mot) {

    int* combinaison = (int*)malloc(n * sizeof(int));

    combinations_recursive(x, n, combinaison, 0, mot);

    free(combinaison);
}

int main(){
    
    int nblettres = intinput("Entrez le nombre de lettres : ");
    char *mot = (char *)malloc(nblettres + 1);
    charinput("Entrez les lettres : ", mot);
    int digits = intinput("Entrez le nombre de digits des mots : ");

    printf(" %.0lf\n", pow(nblettres, digits));
    generate_combinations(nblettres, digits, mot);

    free(mot);

    return 0;
}
