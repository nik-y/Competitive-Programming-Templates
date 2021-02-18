////////////////// T E M P L A T E //////////////////

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

const int N = 1e5 + 5;
int tr[30*N][2], ind = 1, use[30*N];

void up(int x, int ty) {
	int u = 1;
	bfl(j, 31, 0) {
		int bit = x >> j & 1;
		if(not tr[u][bit]) {
			tr[u][bit] = ++ ind;
		}
		u = tr[u][bit];
		use[u] += ty;
	}
}

long qry(int p, int l) {
	int u = 1;
	long res = 0;
	bfl(j, 31, 0) {
		int bit = bool(l&(1<<j));
		int f = bool(p&(1<<j));
		if(bit) {
			res += use[tr[u][0^f]];
		}
		u = tr[u][bit^f];
	}
	return res;
}

int main() {
	test() {
		int t, p, l;
		cin >> t >> p;
		if(t == 1) {
			up(p, '+');
		}
		if(t == 2) {
			up(p, '-');
		}
		if(t == 3) {
			cin >> l;
			cout << qry(p, l) << endl;
		}
	}
}

////////////////////////////////////////////////////





#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
struct TrieNode {
	TrieNode *bit[2];
	int cnt;
	TrieNode() {
		bit[0] = bit[1] = NULL;
		cnt = 0;
	}
};
TrieNode *root;
void add(int x) {
	TrieNode* cur = root;
	for(int i=30; i>=0; i--) {
		int b = (x>>i) & 1;
		if(!cur->bit[b])
			cur->bit[b] = new TrieNode();
		cur = cur->bit[b];
		cur->cnt++;
	}
}
void remove(int x) {
	TrieNode *cur = root;
	for(int i = 30; i >= 0; i --) {
		int b = (x >> i) & 1;
		cur = cur->bit[b];
		cur->cnt --;
	}
}
int query(int x) {
	TrieNode *cur = root;
	int ans = 0;
	for(int i = 30; i >= 0; i --) {
		int b = (x >> i) & 1;
		if(cur->bit[b ^ 1] != NULL && cur->bit[b ^ 1]->cnt > 0) {
			ans += 1 << i;
			cur = cur->bit[b ^ 1];
		}
		else {
			cur = cur->bit[b];
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	root = new TrieNode();
	
	return 0;
}