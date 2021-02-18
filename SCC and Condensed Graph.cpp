 
const int N = 5005;
vector<int> gr[N], gt[N], gc[N];
vector<int> order, comp(N), szz(N);
vector<bool> used(N);
int cycle;

void dfsa(int u) {
	used[u] = true;
	for(int v:gr[u]) 
		if(not used[v]) 
			dfsa(v);
	order.pb(u);
}

void dfsb(int u) {
	used[u] = true;
	comp[u] = cycle;
    szz[cycle] ++;
	for(int v:gt[u]) 
		if(not used[v]) 
			dfsb(v);
}

int main() {
	//n,m
    //make gr - graph and gt - transpose graph

    while(m--) {
    	int x,y;
    	cin>>x>>y;
    	gr[x].pb(y);
    	gt[y].pb(x);
    }

    fl(u,1,n+1) if(not used[u]) 
    	dfsa(u);
    reverse(all(order));

    used.assign(n+1,false);
    for(int u:order) if(not used[u]) {
    	cycle ++;
    	dfsb(u);
    }

    fl(u,1,n+1) {
    	for(int v:gr[u]) {
    		int x,y;
    		x = comp[u];
    		y = comp[v];
    		if(x!=y) {
    			gc[x].pb(y);
    		}
    	}
    }

}
