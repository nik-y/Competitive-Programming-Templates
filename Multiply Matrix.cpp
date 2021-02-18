// https://codeforces.com/problemset/problem/691/E

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
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
#define test()  int tt;  cin>>tt;  while(tt--)  

/////////////////////////

const ll N = 101, M = 1e9+7;
ll mat[N][N];

void add(ll &x, ll y) {
	x = (x+y) % M;
}

void mulmat(ll x[N][N], ll y[N][N]) {
	ll z[N][N];
	fl(i, 0, N) fl(j, 0, N) {
		z[i][j] = 0;
		fl(k, 0, N) {
			add(z[i][j], (x[i][k] * y[k][j]) % M );
		}
	}
	fl(i, 0, N) fl(j, 0, N) {
		x[i][j] = z[i][j];
	}
}

void power(ll mat[N][N], ll k) {
	ll res[N][N];
	fl(i, 0, N) fl(j, 0, N) {
		res[i][j] = (i == j);
	}
	while(k > 0) {
		if(k&1) {
			mulmat(res, mat);
		}
		mulmat(mat, mat);
		k >>= 1;
	}
	fl(i, 0, N) fl(j, 0, N) {
	    mat[i][j] = res[i][j];
	}
}

///////////////////////////

int main() {
	Shazam;
	ll n, k;
	cin >> n >> k;
	ll a[n];
	get(a, n);

	fl(i, 0, n) {
		fl(j, i, n) {
			if(__builtin_popcountll(a[i]^a[j]) % 3 == 0) {
				mat[i][j] = 1;
				mat[j][i] = 1;
			}
		}
	}

    power(mat, k-1);

	ll ans = 0;
	fl(i, 0, n) fl(j, 0, n) {
		add(ans, mat[i][j]);
	}
	cout << ans;
}