// O(nlogn) for sparse graph using set

int d[N], n, inf = 1e6;

void dijkstra(int src) {
	d.fill(n+1,inf);
	set< pair<int,int> > s;
	d[src] = 0;
	s.insert({d[src],src});


	while(not s.empty()) {
		int u = s.begin()->second;
		s.erase(s.begin());

		for(auto p:gr[u]) {  //{vertex,wt}
			int v = p.first, dist = p.second;
			if(d[u] + dist < d[v]) {
				s.erase({d[v],v});
				d[v] = d[u] + dist;
				s.insert({d[v],v});
			}
		}
	}
}



// O(nlogn) for sparse graph using priority queue

int d[N], n, inf = 1e6;
bool mark[N];

void dijkstra(int src) {
	fill(d,d+n+1,inf);
	fill(mark,mark+n+1,false);
	priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
	d[src] = 0;
	pq.push({d[src],src});


	while(not qp.empty()) {
		int u = pq.top().second;
		pq.pop();
		if(mark[u])  	continue;
		mark[u] = true;

		for(auto p:gr[u]) {  //{vertex,wt}
			int v = p.first, dist = p.second;
			if(d[u] + dist < d[v]) {
				d[v] = d[u] + dist;
				pq.push({d[v],v});
			}
		}
	}
}

// O(n^2) for dense graph, m = n^2

int d[N], n, inf = 1e6;
bool mark[N];

void dijkstra(int src){
	fill(d,d + n+1, inf);
	fill(mark, mark + n+1, false);
	d[src] = 0;

	while(true){
		int u = -1;
		int dist = inf;

		for(int i = 1;i <= n;i ++)
			if(!mark[i] and dist >= d[i])
				dist = d[i], u = i;

		if(u == -1)	break;
		mark[u] = true;
		for(auto p : adj[u]) {	//pair(vertex, weight)
			int v = p.first, dist = p.second;
			if(d[v] > d[u] + dist)
				d[v] = d[u] + dist;
	}
}