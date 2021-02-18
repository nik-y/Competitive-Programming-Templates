int par[N], disc[N], low[N], t=0;
bool ap[N], vis[N];

void dfs(int u) {
	int chld = 0;
	vis[u] = true;
	low[u] = disc[u] = t++;

	for(auto v: ed[u]) {
		if(not vis[v]) {
			par[v] = u;
			chld ++;
			dfs(v);
			low[u] = min(low[u],low[v]);
			if(not par[u]  and chld > 1)  
				ap[u] = true;
			if(par[u] and low[v] >= disc[u])
				ap[u] = true;
		}
		else if(v != par[u]) {
			low[u] = min(low[u],disc[v]);
		}
	}
} 