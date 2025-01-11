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

int dp[20][20];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k; cin>>n>>m>>k;
    int x = max((k-1)/m,0);
    int y = max((k-1)%m,0);

    REP(i,0,x) dp[i][0] = 1;
    REP(i,0,y) dp[0][i] = 1;

    REP(i,1,x) REP(j,1,y) dp[i][j] = dp[i-1][j] + dp[i][j-1];

    rep(i,x+1,n) dp[i][y] = 1;
    rep(i,y+1,m) dp[x][i] = 1;

    REP(i,x+1,n) REP(j,y+1,m) dp[i][j] = dp[i-1][j] + dp[i][j-1];

    cout<<dp[x][y] * dp[n-1][m-1]<<'\n';
}