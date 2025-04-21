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
typedef tuple<int,int,int> tiii;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll n,m; cin>>n>>m;
    vector<vector<ll>> v(n+1,vector<ll>(m+2,2e9));
    REP(i,1,n) REP(j,1,m) cin>>v[i][j];

    REP(i,1,n) REP(j,1,m){
        ll x; cin>>x;
        v[i][j] -= x;
        v[i][j]*=v[i][j];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(m+2,2e9));
    REP(i,1,m) dp[0][i] = 0;
    REP(i,1,n) REP(j,1,m){
        dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]}) + v[i][j];
    }
    cout<<*min_element(all(dp[n]))<<'\n';
}