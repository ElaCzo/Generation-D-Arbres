long next(long a, long xn, long c, long m){
    return (a*xn+c)%m;
}

long* generateur(int nombre, long a, long x0, long c, long m){
    long *res = malloc(sizeof(long)*nombre);
    memset(res, 0, sizeof(long)*nombre);
    
    int i;
    long xn =x0;
    for(i=0; i<nombre; i++)
        xn = res[i] = next(a, xn, c, m);

    return res;
}

long* rand48(int nombre, long a, long x0, long c){
    return generateur(nombre, a, x0, c, (1<<48));
}

long* generateur_java(int nombre){
    return rand48(nombre, 25214903917, 0, 11);
}

void affiche(long* entiers, int nombre){
    int i;
    for(i=0; i<nombre; i++){
        printf("%l", entiers[i]);
    }
}

int main(){
    // calcul des 10 premier termes à partir de la graine 0 : 
    int nombre = 10;
    long *alea;
    affiche(alea=generateur_java(nombre), nombre);

    free(alea);
}