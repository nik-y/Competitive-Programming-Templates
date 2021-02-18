//query - maximum weighted edge between u and v
// checked on - https://codeforces.com/contest/609/problem/E

#include <bits/stdc++.h>
 
using namespace std;
#define fl(i,a,b) for(int i=a; i<b; i++)
#define bfl(i,a,b) for(int i=a-1; i>=b; i--)
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ll long long  
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define de(x) cout << #x << " " << x << endl;
#define deb(x,y) cout << x << ' ' << y << endl; 
#define get(a,n) fl(i,0,n)  cin>>a[i];
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";  cout<<endl;
#define test()  int tt;  cin>>tt;  while(tt--)  
const int N = 2e5 + 4;
vector< pair<int, ll> > g[N];

//////////////
int n, m, l, lev[N];

int timer;
vector<int> tin, tout;
vector<vector<long>> up, sp;

void dfslca(int v, int p, long wt)
{
    tin[v] = ++timer;
    up[v][0] = p;
    sp[v][0] = wt;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        sp[v][i] = max(sp[v][i-1], sp[up[v][i-1]][i-1]);
    }

    for (auto pr : g[v]) {
        long u = pr.ff, w = pr.ss;
        if (u != p) {
            lev[u] = lev[v] + 1;
            dfslca(u, v, w);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

long qry(int u, int l) {
    if(l == 0) {
        return 0;
    }
    int k = log2(l), t = l - (1<<k), x = u, i = 0;
    while(t > 0) {
        if(t&1) {
            x = up[x][i];
        }
        t >>= 1;
        i ++;
    }
    return max(sp[u][k], sp[x][k]);
}

long query(int u, int v) {
    int l = lca(u, v);
    long ans = max(qry(u, lev[u] - lev[l]), qry(v, lev[v] - lev[l]));
    return ans;
}

void preprocess(int root) {
    tin.resize(N);
    tout.resize(N);
    timer = 0;
    l = ceil(log2(N));
    up.assign(N, vector<long>(l + 1));
    sp.assign(N, vector<long>(l + 1));
    dfslca(root, root, 0);
}
/////////////////////////


int main() {
    Shazam;
    cin >> n;
    fl(i, 1, n) {
        int x, y;	ll w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    } 

    preprocess(1);

    int m;
    cin >> m;
    fl(i, 0, m) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
}