#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int dp[101][101];
vector<int> v;
int f(int n,int m){
    if(m==0) return 0;
    if(n<=0) return -2e9;
    if(dp[n][m]!=-1) return dp[n][m];
    

    int sum = 0;
    dp[n][m] = f(n-1,m);
    for(int i=n;i>0;i--){
        sum += v[i];
        dp[n][m] = max(dp[n][m], f(i-2,m-1)+sum);
    }
    return dp[n][m];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    v.resize(n+1);
    rep(i,1,n+1) cin>>v[i];
    memset(dp,-1,sizeof(dp));
    cout<<f(n,m)<<'\n';
    
}