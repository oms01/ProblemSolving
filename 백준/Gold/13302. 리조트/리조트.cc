#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 100;
ll dp[MX+5][MX+5]; //i일,쿠폰j개
int day[MX+1];
int main(){
    int n,m; cin>>n>>m;
    rep(i,0,n){
        int x; cin>>x;
        day[x] = 1;
    }

    rep(i,0,MX+5) rep(j,0,MX+5) dp[i][j] = 2e9;

    dp[0][0] = 0;

    REP(i,0,n){
        REP(j,0,MX){
            if(day[i+1]){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            }
            else{
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+10);
                dp[i+3][j+1] = min(dp[i+3][j+1], dp[i][j]+25);
                dp[i+5][j+2] = min(dp[i+5][j+2], dp[i][j]+37);
                if(j>=3) dp[i+1][j-3] = min(dp[i+1][j-3], dp[i][j]);
            }
        }
    }

    ll ans = 2e9;
    REP(i,0,MX){
        ans = min(ans, dp[n][i]);
    }
    cout<<ans*1000<<'\n';
    
}