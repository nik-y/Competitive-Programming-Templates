//f(x) = summation(i=1 to x)  GCD(i,x)

ll phi[M], f[M];          
void pre() {
    fl(i,1,M)   phi[i] = i;
    
    fl(i,2,M) if(phi[i] == i) {
        for(int j=i; j<M; j+=i) 
            phi[j] -= phi[j]/i;
    }
    fl(i,1,M) {
        for(int j=i; j<M; j+=i) 
            f[j] += i*phi[j/i];
    }
}