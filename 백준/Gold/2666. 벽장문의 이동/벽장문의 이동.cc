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

const int MX = 20;
int dp[MX+1][MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    int a,b; cin>>a>>b;
    int t; cin>>t;
    vector<int> v(t);
    rep(i,0,t) cin>>v[i];

    REP(i,0,MX) REP(j,0,MX) REP(k,0,MX) dp[i][j][k] = 2e9;
    dp[min(a,b)][max(a,b)][0] = 0;

    rep(I,0,t){
        int nxt = v[I];
        REP(i,1,n) REP(j,i+1,n){
            dp[min(i,nxt)][max(i,nxt)][I+1] = min(dp[min(i,nxt)][max(i,nxt)][I+1], dp[i][j][I] + abs(j-nxt));
            dp[min(j,nxt)][max(j,nxt)][I+1] = min(dp[min(j,nxt)][max(j,nxt)][I+1], dp[i][j][I] + abs(i-nxt));
        }
    }

    int ans = 2e9;
    REP(i,1,n){
        ans = min(ans, dp[min(i,v[t-1])][max(i,v[t-1])][t]);
    }

    cout<<ans<<'\n';
}