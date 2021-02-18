// set value at position p
// sum on interval [l, r)

const int N = 2e5 + 5;   
int t[2*N], n;

void modify(int p, int value) {  
    for(t[p+=n]=value; p>1; p>>=1)    t[p>>1] = t[p]+t[p^1];
}

int query(int l, int r) {  
    int res = 0;
    for (l+=n,r+=n; l<r; l>>=1, r>>=1) {
        if (l&1)    res += t[l++];
        if (r&1)    res += t[--r];
    }
    return res;
}

int main() {
    cin>>n;
    fl(i,0,n)   cin>>t[n+i];
    bfl(i,n,0)  t[i] = t[i<<1] + t[i<<1|1];
}