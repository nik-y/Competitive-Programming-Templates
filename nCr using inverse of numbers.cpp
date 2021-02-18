const long mod = 1e9+7;

vll natNumInv(N + 1); 
vll fact(N + 1); 
vll factNumInv(N + 1); 


  
void InvofFact() { 
    factNumInv[0] = factNumInv[1] = 1; 
  
    for (int i = 2; i <= N; i++) 
    factNumInv[i] = (natNumInv[i] * factNumInv[i - 1]) % mod; 
} 
  
void InvofNum() { 
    natNumInv[0] = natNumInv[1] = 1; 
    for (int i = 2; i <= N; i++) 
        natNumInv[i] = natNumInv[mod% i] * (mod- mod/ i) % mod; 
} 


ll ncr(ll N, ll R) { 
       ll ans = ((fact[N] * factNumInv[R]) 
              % mod * factNumInv[N - R]) 
             % mod; 
    return ans; 
} 

void factorial() { 
    fact[0] = 1; 

    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % mod; 
    } 
} 

void prep() {
	factorial();
	InvofNum();
	InvofNum();
}

