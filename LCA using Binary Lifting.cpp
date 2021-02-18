//https://www.codechef.com/problems/QUERYT

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
const int N = 4e4 + 4, V = 2e2 + 2;
vector<int> g[N];
int val[N], h[N][V];

//////////////
int n, L;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfslca(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= L; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : g[v]) {
        if (u != p)
            dfslca(u, v);
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
    for (int i = L; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(N);
    tout.resize(N);
    timer = 0;
    L = ceil(log2(N));
    up.assign(N, vector<int>(L + 1));
    dfslca(root, root);
}
/////////////////////////

void dfs(int u, int p) {
    h[u][val[u]] += 1;
    for(int v: g[u]) if(v != p) {
        fl(i, 0, V) {
            h[v][i] = h[u][i];
        }
        dfs(v, u); 
    }
}

int main() {
    Shazam;
    cin >> n;
    fl(i, 0, n) {
        cin >> val[i+1];
    }
    fl(i, 1, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, 0);
    preprocess(1);

    int m;
    cin >> m;
    fl(i, 0, m) {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v), x = val[l], ans = 0;

        fl(i, 1, V) {
            if(__gcd(x, i) != 1) {
                ans += h[u][i] + h[v][i] - 2 * h[l][i] + (val[l] == i);
            }
        }
        cout << ans << endl;
    }
}