#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// NON FONCTIONNEL A REVOIR LES PROJECTIONS

typedef struct{
    int x, y;
}coord;

int input()
{
    int x;
    scanf("%d",&x);
    return x;
}

void input2(int *a, int *b) 
{
    scanf("%d %d", a, b);
}

void input4(int *a, int *b, int *c, int *d) {
    scanf("%d %d %d %d", a, b, c, d);
}

double signedDistance(coord A, coord B, coord P) {
    double ABx = B.x - A.x;
    double ABy = B.y - A.y;
    double APx = P.x - A.x;
    double APy = P.y - A.y;

    double dotProduct = ABx * APx + ABy * APy;
    double distance = dotProduct / (ABx * ABx + ABy * ABy);

    if (distance < 0) {
        distance = -sqrt(APx * APx + APy * APy);
    } else if (distance > 1) {
        double BPx = P.x - B.x;
        double BPy = P.y - B.y;
        distance = -sqrt(BPx * BPx + BPy * BPy);
    } else {
        double projection_x = A.x + distance * ABx;
        double projection_y = A.y + distance * ABy;
        distance = -sqrt((P.x - projection_x) * (P.x - projection_x) + (P.y - projection_y) * (P.y - projection_y));
    }

    return distance;
}

int main() {
    coord A, B;
    input4(&A.x, &A.y, &B.x, &B.y);

    int nbpoint = input();

    coord* locations = (coord*)malloc(nbpoint * sizeof(coord));

    for (int i = 0; i < nbpoint; i++) {
        input2(&locations[i].x, &locations[i].y);
    }

    for (int i = 0; i < nbpoint; i++) {
        double dist = signedDistance(A, B, locations[i]);
        printf("%.6lf\n", dist);
    }

    return 0;
}
