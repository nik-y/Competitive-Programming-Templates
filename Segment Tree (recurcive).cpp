
//query - min of range(and its count),gcd of range
//update - set a number at postion pos to val
const long N = 1e5+5, inf = 1e9+9;
long a[N];
 
struct node {
	long mn;
	long gcd;
	int cnt;
	node operator + (node oth) {
		node res;
		if(mn == oth.mn) {
			res.mn = mn;
			res.cnt = cnt + oth.cnt;
		}
		else if(mn < oth.mn) {
			res.mn = mn;
			res.cnt = cnt;
		}
		else {
			res.mn = oth.mn;
			res.cnt = oth.cnt;
		}
		if(gcd == -1) 			res.gcd = oth.gcd;
		else if(oth.gcd == -1) 	res.gcd = gcd;
		else 					res.gcd = __gcd(gcd, oth.gcd);
		
		return res;
	}
	void operator = (long x) {
		cnt = 1;
		mn = gcd = x;
	}
} t[4*N];
 
void build(int i,int st,int en) {
	if(st == en) {
		t[i] = a[st];
		return;
	}
	int mid = (st + en)/2;
	build(2*i,st,mid);
	build(2*i+1,mid+1,en);
	t[i] = t[2*i] + t[2*i+1];
}
 
node query(int i, int st, int en, int l, int r) {
	if(r<st or l>en) 
		return {inf,-1,0};
	if(l<=st and r>=en) 
		return t[i];
	node x,y;
	int mid = (st + en)/2;
	x = query(2*i,st,mid,l,r);
	y = query(2*i+1,mid+1,en,l,r);
	return x + y;
}

void update(int i, int st, int en, int pos, long val) {
	if(st == en) {
		t[i] = val;
		s[pos] = val;
		return;
	}
	int mid = (st + en)/2;
	if(pos<=mid)	update(2*i,st,mid,pos,val);
	else			update(2*i+1,mid+1,en,pos,val);
	t[i] = t[2*i] + t[2*i+1];
}