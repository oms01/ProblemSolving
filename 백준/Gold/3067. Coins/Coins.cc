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

const int MX = 10'000;
void solve(){
    int n; cin>>n;
    vector<int> coins(n+1,0);
    REP(i,1,n) cin>>coins[i];

    int dp[MX+1];
    fill(&dp[0],&dp[MX+1],0);
    dp[0] = 1;

    REP(i,1,n){
        REP(j,0,MX){
            if(coins[i]+j <= MX) dp[coins[i]+j] += dp[j];
        }
    }

    int x; cin>>x;
    cout<<dp[x]<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--) solve();
}