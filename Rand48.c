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

unsigned long long* rand48(int nombre, unsigned long long a, 
unsigned long long x0, unsigned long long c){
    return generateur(nombre, a, x0, c, (1<<48));
}

unsigned long long* generateur_java(int nombre){
    return rand48(nombre, 25214903917, 0, 11);
}

void affiche(unsigned long long* entiers, int nombre){
    int i;
    for(i=0; i<nombre; i++){
        printf("%l", entiers[i]);
    }
}

int main(){
    // calcul des 10 premier termes à partir de la graine 0 : 
    int nombre = 10;
    unsigned long long *alea;
    affiche(alea=generateur_java(nombre), nombre);

    free(alea);
}