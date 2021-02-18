// take care of n
// note : always 1 based indexing of BIT
// use - prefix sum,
//	   - update element, sum of range	qry(r)-qry(l-1)	
//     - update range, query on element up(l,x), up(r+1,-x)

const int N=1e5+5;
int t[N];
 
void up(int p, int v) {
    if(p <= 0) return;
    for(; p <= N; p += (p&-p)) {
    	t[p] += v;
    } 
}
ll qry(int p) {
    ll res = 0;
    for(; p > 0; p -= (p&-p)) {
    	res += t[p];
    }
    return res;
}

// like lower_bound
// find (first) position where prefix sum is prefsum or greater

int posof(ll prefsum){
    int pos = 0;
    ll sum = 0;
    for(int i = 23; i>=0 ; --i){
        if((pos + (1<<i) <= N) && (sum + t[pos + (1<<i)] < prefsum)){
            pos += (1<<i);
            sum += t[pos];
        }
    }
    return pos+1;
}