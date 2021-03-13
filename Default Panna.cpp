////////////////// T E M P L A T E //////////////////

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define fl(ii,a,b) for(int ii=a; ii<b; ii++)
#define bfl(ii,a,b) for(int ii=a-1; ii>=b; ii--)
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pll pair<ll, ll>
#define vec vector 
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define sz(x) ((int)(x).size())
#define get(a,n) fl(ii,0,n)  cin>>a[ii];
#define pr(a,n) fl(ii,0,n) cout<<a[ii]<<" ";	cout<<endl;
#define prt(a,n,m) fl(ii,0,n) fl(jj,0,m) cout<<a[ii][jj]<<" \n"[jj==m-1];
#define test()  int tt;  cin>>tt;  while(tt--) 

#define de(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

///////////////////// C O D E /////////////////////

const ll N = 2e5 + 5, M = 1e9 + 7, inf = 1e18;

int main() {
	Shazam;
	
}

////////////////////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define ll long long 

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	int tt;
	cin >> tt;
	while(tt --) {
		
	}
}



////////// HackerRank ///////////

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ofstream fout(getenv("OUTPUT_PATH"));

	

    fout << ans << "\n";

	fout.close();
    return 0;
}
