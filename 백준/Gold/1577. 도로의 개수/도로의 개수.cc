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

set<pair<pii,pii>> s;
ll dp[111][111];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int k; cin>>k;
    rep(i,0,k){
        int a,b,c,d; cin>>a>>b>>c>>d;
        s.insert({{a+1,b+1},{c+1,d+1}});
    }
    n++; m++;
    REP(i,0,n) dp[i][0] = 0;
    REP(i,0,m) dp[0][i] = 0;

    dp[1][1] = 1;
    REP(i,1,n) REP(j,1,m){
        if(!s.count({{i,j},{i-1,j}}) && !s.count({{i-1,j},{i,j}}))
            dp[i][j] += dp[i-1][j];
        if(!s.count({{i,j},{i,j-1}}) && !s.count({{i,j-1},{i,j}}))
            dp[i][j] += dp[i][j-1];
    }

    cout<<dp[n][m]<<'\n';


}