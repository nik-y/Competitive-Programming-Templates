const int N = 2e5 + 5, M = 1e9 + 7;

void adds(ll &x, ll y) {
    x = (x + y) % M;
}

void muls(ll &x, ll y) {
    x = x * y % M;
}

ll add(ll x, ll y) {
    return (x + y) % M;
}

ll mul(ll x, ll y) {
    return x * y % M;
}        
 
ll fact[N];
void factorial() {
    fact[0] = 1;
    for(int i = 1; i < N; i ++) {
        fact[i] = mul(fact[i-1], i);
    }
}

ll pw(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1)  {
            muls(res, x);
        }
        muls(x, x);
        y >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return pw(x, M-2);
}

ll C(ll n, ll r) {
    if(r > n or r < 0 or n < 0) return 0;
    return  mul(fact[n], inv(mul(fact[r], fact[n-r])));
}
