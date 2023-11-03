#include <stdio.h>
#include <stdlib.h>

// FONCTIONNEL

typedef struct{
    int x1, y1, x2, y2;
}superficie;

int input(char phrase[]){
    int x;
    printf("%s",phrase);scanf("%d",&x);
    return x;
}

void input4(int *a, int *b, int *c, int *d) {
    scanf("%d %d %d %d", a, b, c, d);
}

int calcul_terrain(superficie coord_aeroport, superficie propriete[], int nbpropriete){

    int aire_aerport = (coord_aeroport.x2 - coord_aeroport.x1 ) * (coord_aeroport.y2 - coord_aeroport.y1 );
    
    for(int i = 0; i < nbpropriete; i++){
        if (propriete[i].x1 >= coord_aeroport.x1 && propriete[i].y1 >= coord_aeroport.y1 && propriete[i].x2 <= coord_aeroport.x2 && propriete[i].y2 <= coord_aeroport.y2) {
            aire_aerport -= (propriete[i].x2 - propriete[i].x1) * (propriete[i].y2 - propriete[i].y1);
        }else if (propriete[i].x2 > coord_aeroport.x1 && propriete[i].y2 > coord_aeroport.y1 && propriete[i].x1 < coord_aeroport.x2 && propriete[i].y1 < coord_aeroport.y2) {
            int x1 = (propriete[i].x1 > coord_aeroport.x1) ? propriete[i].x1 : coord_aeroport.x1;
            int y1 = (propriete[i].y1 > coord_aeroport.y1) ? propriete[i].y1 : coord_aeroport.y1;
            int x2 = (propriete[i].x2 < coord_aeroport.x2) ? propriete[i].x2 : coord_aeroport.x2;
            int y2 = (propriete[i].y2 < coord_aeroport.y2) ? propriete[i].y2 : coord_aeroport.y2;
            aire_aerport -= (x2 - x1) * (y2 - y1);
        }
    }
    return aire_aerport;
}

int main()
{
    superficie coord_aeroport;
    input4(&coord_aeroport.x1, &coord_aeroport.y1, &coord_aeroport.x2, &coord_aeroport.y2);

    int nbpropriete = input("");
    
    superficie* propriete = (superficie*)malloc(nbpropriete * sizeof(superficie));
    for (int i = 0; i < nbpropriete; i++)
    {
        input4(&propriete[i].x1, &propriete[i].y1, &propriete[i].x2, &propriete[i].y2);
    }

    printf("%d", calcul_terrain(coord_aeroport, propriete, nbpropriete));
    
    free(propriete);
    return 0;
}