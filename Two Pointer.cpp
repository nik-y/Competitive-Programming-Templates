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


int main() {
	Shazam;
	int n, k;
	cin >> n;
	int a[n];
	get(a, n);

	int r = 0;
	fl(l, 0, n) {
		while(r < n) {
			add(a[r]);
			if(cur > k) { // if invalid [l, r)
				rem(a[r]);
				break;
			}
			r ++;
		}
		//got a valid [l, r)
		rem(a[l]);
	}
}