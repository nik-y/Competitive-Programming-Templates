int par[N], disc[N], low[N], t=0;
bool vis[N];

void dfs(int u) {
	vis[u] = true;
	low[u] = disc[u] = t++;

	for(auto v: ed[u]) {
		if(not vis[v]) {
			par[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
			if(low[v] > disc[u])
				cout << u << " " << v << endl;
		}
		else if(v != par[u]) {
			low[u] = min(low[u], disc[v]);
		}
	}
} 