const int N=2e5+5;

vector<int> p(N), sz(N,1);

int find(int a) {
    return p[a] = p[a] == a? a: find(p[a]);
}

void un(int a,int b) {
    a = find(a);    
    b = find(b);
    if(a!=b) {
        if(sz[a]>sz[b])     swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
    }
}

fl(i,1,n+1)  p[i] = i;