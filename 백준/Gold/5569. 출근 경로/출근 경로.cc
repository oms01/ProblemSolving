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
const int MOD = 100'000;
ll dp[MX+2][MX+2][2][2]; //i,j에 왼/위 방향에서, 꺾불가능/가능
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    
    REP(i,2,n) dp[i][1][0][0] = 1;
    REP(i,2,m) dp[1][i][1][0] = 1;

    REP(i,2,n){
        REP(j,2,m){
            dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1])%MOD;
            dp[i][j][0][1] = dp[i-1][j][1][0]%MOD;
            dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1])%MOD;
            dp[i][j][1][1] = dp[i][j-1][0][0]%MOD;
        }
    }

    ll ans = 0;
    REP(i,0,1) REP(j,0,1) ans+=dp[n][m][i][j];
    cout<<ans%MOD<<'\n';
    
}