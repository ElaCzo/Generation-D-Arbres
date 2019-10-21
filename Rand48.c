long next(long a, long xn, long c, long m){
    return (a*xn+c)%m;
}

long* generateur(int nombre, long a, long xn, long c, long m){
    long *res = malloc(sizeof(long)*nombre);
    memset(res, 0, sizeof(long)*nombre);
    
    int i;
    for(i=0; i<nombre; i++)
        res[i]= next(a, xn, c, m);

    return res;
}