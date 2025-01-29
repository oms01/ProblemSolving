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

ll dp[202][202];
const ll MOD = 1e9;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    REP(i,0,200) dp[1][i] = i;

    REP(i,2,200){
        REP(j,1,200){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }

    int n,k; cin>>n>>k;
    cout<<dp[n][k]<<'\n';

}