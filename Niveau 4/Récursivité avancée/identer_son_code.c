#include <stdio.h>
#include <string.h>

// FONCTIONNEL

#define ident(s) ident_def(s, 0, 0)

#define CHARMAX 1000

void charinput(char phrase[],char *mot){
    printf("%s",phrase);scanf(" %s", mot);
    mot[strcspn(mot, "\n")] = '\0';
}

void printtab(int a){
    for (int i = 0; i < a; i++)
    {
        printf("\t");
    }
}

void ident_def(char indentation[], int i, int nbtab){
    if(indentation[i] == '\0')return;
    else{
        if(i == 0){
            printf("%c\n",indentation[i]);
            ident_def(indentation, i+1, nbtab);
        }else{
            if((int)indentation[i-1] == 125 && (int)indentation[i] == 125)
            {   
                nbtab-=1;
            }else if ((int)indentation[i-1] == 123 && (int)indentation[i] == 123)
            {
                nbtab+=1;
            }
            printtab(nbtab);
            printf("%c\n",indentation[i]);
            ident_def(indentation, i+1, nbtab);
        }
    }
}

int main(){
    
    char indentation[CHARMAX];
    charinput("",indentation);

    ident(indentation);

    return 0;
}