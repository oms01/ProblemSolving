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
ll dp[1001][1001];
const ll MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    REP(i,1,m) dp[1][i] = 1;
    REP(i,1,n) dp[i][1] = 1;

    REP(i,2,n) REP(j,2,m){
        dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1])%MOD;
    }
    cout<<dp[n][m]<<'\n';
}