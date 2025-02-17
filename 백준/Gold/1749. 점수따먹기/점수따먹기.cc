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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

/*----------------------*/

const int MX = 200;
ll dp[MX+1][MX+1];

ll cal(ll a,ll b, ll x, ll y){
    return dp[x][y] - dp[a-1][y] - dp[x][b-1] + dp[a-1][b-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n,m; cin>>n>>m;
    REP(i,1,n) REP(j,1,m) cin>>dp[i][j];

    REP(i,1,n){
        REP(j,1,m) dp[i][j] += dp[i][j-1];
    }

    REP(j,1,m){
        REP(i,1,n) dp[i][j] += dp[i-1][j];
    }

    ll ans = -2e9;
    REP(a,1,n) REP(b,1,m){
        REP(x,a,n) REP(y,b,m){
            ans = max(ans,cal(a,b,x,y));
        }
    }
    cout<<ans<<'\n';
}