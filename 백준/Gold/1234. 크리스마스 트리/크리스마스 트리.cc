#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

ll dp[11][101][101][101];
int n,m,k,l;
ll com[101][101];
ll comb(int N, int M){
    if(N==M || M==0) return com[N][M] = 1;
    if(com[N][M]!=0) return com[N][M];
    return com[N][M] = comb(N-1,M-1) + comb(N-1,M);
}
ll f(int i,int j,int k,int l){
    if(i<0||j<0||k<0||l<0) return 0;
    if(i==0){
        return dp[i][j][k][l] = 1;
    }
    ll& tmp = dp[i][j][k][l];
    if(tmp!=-1) return tmp;

    ll t1 = 0;
    t1 = f(i-1, j-i,k,l) + f(i-1,j,k-i,l) + f(i-1,j,k,l-i);

    ll t2 = 0;
    if(i%2==0){
        t2 = f(i-1,j-i/2,k-i/2,l) + f(i-1,j-i/2,k,l-i/2) + f(i-1,j,k-i/2,l-i/2);
        t2*=comb(i,i/2);
    }

    ll t3 = 0;
    if(i%3==0){
        t3 = f(i-1,j-i/3,k-i/3,l-i/3);
        t3*=comb(i,i/3)*comb(i-i/3,i/3);
    }
    
    return tmp = (t1+t2+t3);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k>>l;

    rep(i,0,11) rep(j,0,101) rep(k,0,101) rep(l,0,101){
        dp[i][j][k][l] = -1;
    }

    cout<<f(n,m,k,l)<<'\n';
    
}