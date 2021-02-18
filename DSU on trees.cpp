//https://codeforces.com/problemset/problem/600/endl
////////////////// T E M P L A T E //////////////////

#include <bits/stdc++.h>
 
using namespace std;
#define fl(i,a,b) for(int i=a; i<b; i++)
#define bfl(i,a,b) for(int i=a-1; i>=b; i--)
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define vec vector 
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define sz(x) ((int)(x).size())
#define get(a,n) fl(i,0,n)  cin>>a[i];
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
#define prt(a,n,m) fl(i,0,n) fl(j,0,m) cout<<a[i][j]<<" \n"[j==m-1];
#define test()  int tt;  cin>>tt;  while(tt--) 

#define de(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

///////////////////// C O D E /////////////////////


const int N = 1e5 +5;
ll cnt[N], f[N], ans, mx_cnt, fans[N];
vec<int> g[N], eu, s(N, 1);
long a[N], st[N], en[N], tmr;

void dfs(int u, int p) {
	eu.pb(u);
	st[u] = tmr ++;
	for(int v : g[u]) if(v != p) {
		dfs(v, u);
		s[u] += s[v];
	}
	en[u] = tmr - 1;
}

void rem(int u) {
	ll col = a[u];
 	f[cnt[col]] -= col;
 	cnt[col] --;
 	f[cnt[col]] += col;

 	if(f[mx_cnt] == 0) {
 		mx_cnt --;
 	}
 	ans = f[mx_cnt];
}
void add(int u) {
   	ll col = a[u];
   	f[cnt[col]] -= col;
   	cnt[col] ++;
   	f[cnt[col]] += col;

   	if(cnt[col] > mx_cnt) {
   		mx_cnt ++;
   	}
   	ans = f[mx_cnt];
}

vec<int> *cur[N];

void dfsu(int u, int p, bool keep) {
	int bc = -1, bs = -1;
	for(int v : g[u]) if(v != p) {
		if(s[v] > bs) {
			bs = s[v];
			bc = v;
		}
	}
	for(int v : g[u]) if(v != p and v != bc) {
		dfsu(v, u, 0);
	}
	if(bc != -1) {
		dfsu(bc, u, 1);
		cur[u] = cur[bc];
	}
	else {
		cur[u] = new vec<int> ();
	}
	cur[u]->pb(u);
	add(u);
	for(int v : g[u]) if(v != p  and v != bc) {
		for(int x : *cur[v]) {
			cur[u]->pb(x);
			add(x);
		}
	}
	fans[u] = ans;
	if(not keep) {
		for(int x : *cur[u]) {
			rem(x);
		}
	}
}

int main() {
    Shazam;
    int n;
    cin >> n;
    get(a, n);
    fl(i, 0, n-1) {
    	int x, y;
    	cin >> x >> y;
    	g[x-1].pb(y-1);
    	g[y-1].pb(x-1);
    }

    dfs(0, -1);
    dfsu(0, -1, 1);
    pr(fans, n);
}

////////////////////////////////////////////////////