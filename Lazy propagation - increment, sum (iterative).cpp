// increment (each element in) range with val
// sum query over a range
 	
const int N = 4e5+5;
int t[2*N];	int d[N], n, h;


void calc(int p, int k) {
  t[p] = t[p<<1] + t[p<<1|1] + k * d[p];
}

void apply(int p, int value, int k) {
  t[p] += k * value;
  if (p < n) d[p] += value;
}

void build(int l, int r) {
  int k = 2;
  for (l += n, r += n-1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (int i = r; i >= l; --i) calc(i, k);
  }
}

void push(int l, int r) {
  int s = h, k = 1 << (h-1);
  for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
      apply(i<<1, d[i], k);
      apply(i<<1|1, d[i], k);
      d[i] = 0;
    }
}

void up(int l, int r, int value) {
  if (value == 0)       return;
  int l0 = l, r0 = r, k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l&1) apply(l++, value, k);
    if (r&1) apply(--r, value, k);
  }
  build(l0, l0 + 1);
  build(r0 - 1, r0);
}

int qry(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    Shazam;
	cin>>n;
	
	fl(i,0,n)       cin>>t[i+n]; 
	bfl(i,n,0) 		t[i] = t[i<<1] + t[i<<1|1];
	h = sizeof(int) * 8 - __builtin_clz(n);
    
	test() {
		int x,l,r,val;
		cin>>x;
		if(x == 1){
		    cin>>l>>r>>val;  l--;
			up(l,r,val);
		}
		else {
			cin>>l>>r;     l--;
		    cout<<qry(l,r)<<endl;
		}
	}
}
