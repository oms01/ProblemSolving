#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int dp[11][11][3];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    REP(i,1,10) REP(j,0,10) REP(k,0,2) dp[i][j][k] = 2e9;
    REP(i,1,n) REP(j,1,m){
        int x; cin>>x;
        REP(k,0,2) dp[i][j][k] = x;
    }
    

    REP(i,1,n) REP(j,1,m) REP(k,0,2){
        int d = 2e9;
        REP(l,0,2){
            if(k==l) continue;
            d = min(d,dp[i-1][j+k-1][l]);
        }
        dp[i][j][k]+=d;
    }

    int ans = 2e9;
    REP(j,1,m) REP(k,0,2) ans = min(ans,dp[n][j][k]);

    cout<<ans<<'\n';
}