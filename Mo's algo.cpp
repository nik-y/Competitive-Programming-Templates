
#include <bits/stdc++.h>

using namespace std;
#define fl(i,a,b) for(int i=a; i<b; i++)
#define bfl(i,a,b) for(int i=a-1; i>=b; i--)
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ll long long  
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define de(x) cout << #x << " " << x << endl;
#define deb(x,y) cout << x << ' ' << y << endl;	
#define get(a,n) fl(i,0,n)  cin>>a[i];
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
#define test()  int tt;  cin>>tt;  while(tt--)  

const int N = 1e5 +5;
ll cnt[N], ans;
ll a[N];

void remove(int i) {
    if(a[i] < N) {
        if(cnt[a[i]] == a[i]) {
            ans --;
        }
        cnt[a[i]] --;
        if(cnt[a[i]] == a[i]) {
            ans ++;
        }
    }
}
void add(int i) {
    if(a[i] < N) {
        if(cnt[a[i]] == a[i]) {
            ans --;
        }
        cnt[a[i]] ++;
        if(cnt[a[i]] == a[i]) {
            ans ++;
        }
    }
}
const int block_size = 320;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<ll> solve(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = ans;
    }
    return answers;
}
int main() {
    Shazam;
    int n, m;
    cin >> n >> m;
    fl(i, 0, n) {
    	cin >> a[i];
    }
    vector<Query> queries;
    fl(i, 0, m) {
    	int l, r;
    	cin >> l >> r;
    	queries.pb({l-1,r-1,i});
    }

    vector<ll> ans = solve(queries);
    fl(i, 0, ans.size()) {
        cout << ans[i] << endl;
    }
}




//////////////////// Faster //////////////////////////

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const int BLK = 900;
struct Query {
    int l, r, id;
    void read(int _i) {
        cin >> l >> r;
        id = _i;
    }
    bool operator < (Query a) {
        if(l / BLK != a.l / BLK) return l / BLK < a.l / BLK;
        return ((l / BLK) & 1 ? r < a.r : r > a.r);
    }
} Q[MAX];
ll ans[MAX], cur = 0;
int f[MAX], a[MAX], n, m;
void add(int x) {
    if(x > 1e5) return;
    if(f[x] == x) cur --;
    f[x] ++;
    if(f[x] == x) cur ++;
}
void remove(int x) {
    if(x > 1e5) return;
    if(f[x] == x) cur --;
    f[x] --;
    if(f[x] == x) cur ++;
}
void mos_algorithm() {
    sort(Q, Q + m);
    int l = Q[0].l, r = Q[0].l - 1;
    for(int i = 0; i < m; i ++) {
        while(l < Q[i].l) remove(a[l ++]);
        while(l > Q[i].l) add(a[-- l]);
        while(r < Q[i].r) add(a[++ r]);
        while(r > Q[i].r) remove(a[r --]);
        ans[Q[i].id] = cur;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)  cin >> a[i];
    for(int i = 0; i < m; i ++) Q[i].read(i);
    mos_algorithm();
    for(int i = 0; i < m; i ++) cout << ans[i] << "\n";
    
    return 0;
}
