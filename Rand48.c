#include <stdio.h>
#include <stdlib.h>
int Xn = 0;
int cpt = 0;
unsigned long long rand = 123456789;

unsigned long long next(unsigned long long a, 
unsigned long long xn, unsigned long long c, unsigned long long m){
    return (a*xn+c)%m;
}

unsigned long long* generateur(int nombre, unsigned long long a, 
unsigned long long x0, unsigned long long c, unsigned long long m){
    long *res = malloc(sizeof(long)*nombre);
    memset(res, 0, sizeof(long)*nombre);
    
    int i;
    unsigned long long xn =x0;
    for(i=0; i<nombre; i++)
        xn = res[i] = next(a, xn, c, m);

    return res;
}

unsigned long long* rand48(int nombre, unsigned long long x0){
    return generateur(nombre, 25214903917, x0, 11, (1<<48));
}

void affiche(unsigned long long* entiers, int nombre){
    int i;
    for(i=0; i<nombre; i++){
        printf("%llu", entiers[i]);
    }
}

// On désire une graine > 2^40
unsigned long long* initialisation_generateur(int nombre, unsigned long long graine){
    if(graine > (1<<40))
        return rand48(nombre, graine);
    else
        return rand48(nombre, graine+(1<<40));
}

char bit_suivant(){
    if(cpt == 48){
        cpt = 0;
        Xn=initialisation_generateur(1, rand);
        rand=Xn;
    }

    char res = (Xn&1);
    Xn >>= 1;

    cpt++;
    return res;
}

int main(){
    // calcul des 10 premier termes à partir de la graine 0 : 
    int nombre = 10;
    unsigned long long *alea;
    affiche(alea=rand48(nombre), nombre);

    free(alea);
}