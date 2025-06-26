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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const ll MOD = 1e9+9;
const int MX = 1000;
ll dp[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
    REP(i,4,MX){
        REP(j,2,i){
            dp[i][j] = dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1];
            dp[i][j]%=MOD;
        }
    }


    ll t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        ll sum = 0;
        REP(i,0,m) sum = (sum+dp[n][i])%MOD;
        cout<<sum<<'\n';
    }
}