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

const ll MOD = 1'000'000'007;
ll dp[2'000][3];
//i자리수에, 자릿수합%3==j
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;

    dp[1][2] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }

    cout<<dp[n][0]<<'\n';

}