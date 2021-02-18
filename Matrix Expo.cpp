/*
	f(i)=a*f(i-1)+b*f(i-2)+c*f(i-3)+(i*(i+1))/2, (i>=4)

Input:
First line contains t,the no. of testcases.
Second line contains 3 integers, the no. of apples given to 1st ,2nd and 3rd students.
Next line contains 3 integers a,b and c.
The last line contains n, the nth student.

*/
#include <bits/stdc++.h>
 
#define fl(i,st,en) for(int i=st; i<en; i++)
#define bfl(i,st,en) for(int i=st-1; i>=en; i--)
#define flash ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define ss second
#define ff first
#define all(c) c.begin(),c.end()
#define tr(c,it) for( auto it=c.begin(); it!=c.end(); it++)
#define endl "\n"
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define print(x,n) fl(i,0,n)   cout << x[i] << " "; cout<<endl;
#define test()  int t;  cin>>t;  while(t--)  
using namespace std;
const int mod = 1e9+7, N=6;

struct Matrix {
    ll mat[N][N];
    Matrix() {
        fl(i,0,N) fl(j,0,N)     mat[i][j] = (i==j);
    }
    Matrix(int a, int b, int c) {
        ll t[N][N] = { {a,b,c,1,0,0},
                       {1,0,0,0,0,0},
                       {0,1,0,0,0,0},
                       {0,0,0,1,1,1},
                       {0,0,0,0,1,1},
                       {0,0,0,0,0,1} };
        fl(i,0,N)   fl(j,0,N)   mat[i][j] = t[i][j];
    }
    Matrix(const Matrix &B) {
        fl(i,0,N) fl(j,0,N)     mat[i][j] = B.mat[i][j];
    }
    Matrix operator *(const Matrix &B){
        Matrix C;
        fl(i,0,N) fl(j,0,N) {
            C.mat[i][j] = 0;
            fl(k,0,N)  C.mat[i][j] = (C.mat[i][j] + mat[i][k] * B.mat[k][j])%mod; 
        }
        return C;
    }
};
Matrix pw(Matrix M,ll y) {
    Matrix R;
    while(y) {
        if(y&1)   R = R*M;
        M = M*M;  y>>=1;
    }
    return R;
}

ll a,b,c, x,y,z, n;

ll ans(Matrix M) {
    ll fans = M.mat[0][0]*z + M.mat[0][1]*y + M.mat[0][2]*x 
            + M.mat[0][3]*10 + M.mat[0][4]*4 + M.mat[0][5]*1;
    return fans %mod;
}
int main() {
    flash;
    test() {
        cin>>x>>y>>z>>a>>b>>c>>n;
        if(n==1)        cout<<a;
        else if(n==2)   cout<<b;
        else if(n==3)   cout<<c;
        else{
            Matrix M(a,b,c);
            M = pw(M,n-3);
            cout<<ans(M)<<endl;
        }
    }
}