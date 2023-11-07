#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// FONCTIONNEL

typedef struct{
    int x, y;
}coord;

int input(char phrase[]){
    int x;
    printf("%s",phrase);scanf("%d",&x);
    return x;
}

void input2(int *a, int *b) {
    scanf("%d %d", a, b);
}

double calcul_dist(coord tour, coord maison){
    return sqrt(pow(tour.x - maison.x, 2) + pow(tour.y - maison.y, 2));
}

int main()
{   
    coord tour;
    input2(&tour.x, &tour.y);

    int nbmaison = input("");
    coord* maisons = (coord*)malloc(nbmaison * sizeof(coord));

    double* dist = (double*)malloc(nbmaison * sizeof(double));

    for (int i = 0; i < nbmaison; i++)
    {
        input2(&maisons[i].x, &maisons[i].y);
        dist[i] = calcul_dist(tour, maisons[i]);
    }

    double min = dist[0];
    int index = 0;

    for (int i = 0; i < nbmaison; i++) {
        if (dist[i] < min) {
            min = dist[i];
            index = i; 
        }
    }

    printf("%d %d",maisons[index-1].x, maisons[index-1].y);

    return 0;
}
