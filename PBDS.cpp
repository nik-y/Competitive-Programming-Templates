////////////////// T E M P L A T E //////////////////
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
using namespace std;
#define fl(i,a,b) for(int i=a; i<b; i++)
#define bfl(i,a,b) for(int i=a-1; i>=b; i--)
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define vec vector 
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define sz(x) ((int)(x).size())
#define get(a,n) fl(i,0,n)  cin>>a[i];
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
#define prt(a,n,m) fl(i,0,n) fl(j,0,m) cout<<a[i][j]<<" \n"[j==m-1];
#define test()  int tt;  cin>>tt;  while(tt--) 

#define de(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

typedef
tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

///////////////////// C O D E /////////////////////

const ll M = 1e9+7, inf = 1e18;


int main() {
	Shazam;
	ordered_set s;
	// for int
	// s.find_by_order(x)
	// s.order_of_key(x)
}

////////////////////////////////////////////////////