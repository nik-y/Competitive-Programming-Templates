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

const ll N = 2e5 + 5, M = 1e9 + 7, inf = 1e18;

vec<int> cyclic_shifts(string s) {
	int n = sz(s), m = 256;
	vec<int> p(n), c(n), cnt(max(n, m));
	fl(i, 0, n) {
		cnt[s[i]] ++;
	}
	fl(i, 1, m) {
		cnt[i] += cnt[i-1];
	}
	fl(i, 0, n) {
		p[--cnt[s[i]]] = i;
	}

	int cls = 1;
	c[p[0]] = cls-1;
	fl(i, 1, n) {
		if(s[p[i]] != s[p[i-1]]) {
			cls ++;
		}
		c[p[i]] = cls-1;
	}

	vec<int> pn(n), cn(n);
	for(int h = 0; (1 << h) < n; h ++) {
		fl(i, 0, n) {
			pn[i] = p[i] - (1 << h);
			if(pn[i] < 0) {
				pn[i] += n;
			}
		}
		fill(all(cnt), 0);
		fl(i, 0, n) {
			cnt[c[pn[i]]] ++;
		}
		fl(i, 1, cls) {
			cnt[i] += cnt[i-1];
		}
		bfl(i, n, 0) {
			p[--cnt[c[pn[i]]]] = pn[i];
		}
		cls = 1;
		cn[p[0]] = cls-1;
		fl(i, 1, n) {
			pair<int, int> a, b;
			a = {c[p[i]], c[(p[i]+(1<<h))%n]};
			b = {c[p[i-1]], c[(p[i-1]+(1<<h))%n]};
			if(a != b) {
				cls ++;
			}
			cn[p[i]] = cls-1;
		}
		c.swap(cn);
	}
	return p;
}

vec<int> prefix_array(string s) {
	s += '$';
	vec<int> ans = cyclic_shifts(s);
	ans.erase(ans.begin());
	return ans;
}

int main() {
	Shazam;
	string s;
	cin >> s;
	vec<int> a = prefix_array(s);
	pr(a, sz(s)+1);
}

////////////////////////////////////////////////////