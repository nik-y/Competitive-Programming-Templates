// up - inc [l,r] by v; 
// qry - min [l,r]
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5+5;
ll a[N], lazy[4*N], inf = 1e18;
 
struct node {
	ll val;
	node() {
		val = inf;
	}
	node operator + (node oth) {
		node res;
		res.val = min(val, oth.val);
		return res;
	}
	node operator = (ll v) {
		val = v;
	}
} t[4*N];
 
void build(int i, int st, int en) {
	if(st == en) {
		t[i] = a[st];
		return;
	}
	int mid = (st + en)/2;
	build(2*i, st, mid);
	build(2*i+1, mid+1, en);
	t[i] = t[2*i] + t[2*i+1];
}
 
void propagate(int i, int st, int en) {
	if(lazy[i]) {
		t[i] = t[i].val + lazy[i];
		if(st != en) {
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
}
 
void update(int i, int st, int en, int l, int r, ll v) {
	propagate(i, st, en);
	if(st > r or en < l) {
		return;
	}
	if(st >= l and en <= r) {
		lazy[i] += v;
		propagate(i, st, en);
		return;
	}
	int mid = (st + en)/2;
	update(2*i, st, mid, l, r, v);
	update(2*i+1, mid+1, en, l, r, v);
	t[i] = t[2*i] + t[2*i+1];
}
 
node query(int i, int st, int en, int l, int r) {
	if(st > r or en < l) {
	    node dummy;
		return dummy;
	}
	propagate(i, st, en);
	if(st >= l and en <= r) {
		return t[i];
	}
	int mid = (st + en)/2;
	node x = query(2*i, st, mid, l, r);
	node y = query(2*i+1, mid+1, en, l, r);
	return x + y;
}
 
int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL); cout.tie(NULL);
    
	int n, q;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(1, 0, n-1);
	
	cin >> q;
	string s; 
	getline(cin, s);
	while(q--) {
		int l, r, v;
		getline(cin, s);
		stringstream ss;
		ss << s;
		if(ss >> l >> r >> v) {
			if(l <= r) {
				update(1, 0, n-1, l, r, v);
			}
			else {
				update(1, 0, n-1, 0, r, v);
				update(1, 0, n-1, l, n-1, v);
			}
		}
		else {
			node x, y;
			if(l <= r) {
				x = query(1, 0, n-1, l, r);
			}
			else {
				x = query(1, 0, n-1, 0, r);
				y = query(1, 0, n-1, l, n-1);
			}
			cout << (x + y).val << endl;
		}
	}
}