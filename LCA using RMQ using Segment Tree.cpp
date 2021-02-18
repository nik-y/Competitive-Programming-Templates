// 1 based indexing for tree, with 1 as root
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5, inf = 1e6;
vector<int> ed[N];
vector<int> euler, h(N), first(N), t(4*N);

void dfs_lca(int u, int p, int d) {
	first[u] = euler.size();
	euler.push_back(u);
	h[u] = d;
	for(auto v: ed[u]) if(v != p) {
		dfs_lca(v,u,d+1);
		euler.push_back(u);
	}
}

void build(int i, int st, int en) {
	if(st == en) {
		t[i] = euler[st];
		return;
	}
	int mid = (st+en)/2;
	build(2*i, st, mid);
	build(2*i+1, mid+1, en);
	t[i] = h[t[2*i]] < h[t[2*i+1]]? t[2*i] : t[2*i+1];
}

int query(int i, int st, int en, int l, int r) {
	if(en<l or st>r) {
		return 0;
	}
	if(st>=l and en<=r) {
		return t[i];
	}
	int x, y, mid = (st+en)/2;
	x = query(2*i, st, mid, l, r);
	y = query(2*i+1, mid+1, en, l, r);
	return h[x] < h[y]? x : y;
}

void lca_ready() {
	h[0] = inf;
	dfs_lca(1,0,0);
	int n = euler.size();
	build(1, 0, n-1);
}

int lca(int u, int v) {
	int l = first[u], r = first[v], n = euler.size();
	if(l > r) swap(l,r);
	return query(1, 0, n-1, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	lca_ready();
	
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << endl;
	}
}
