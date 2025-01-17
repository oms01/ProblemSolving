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
const ll MOD = 1'000'000'009;
ll dp[100'001][5];
void init(){
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    REP(i,4,100'000){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2])%MOD;
    }

    REP(i,1,100'000){
        dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3])%MOD;
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<dp[n][0]<<'\n';
    }

}