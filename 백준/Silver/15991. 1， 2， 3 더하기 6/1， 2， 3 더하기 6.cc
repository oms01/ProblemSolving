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

ll dp[100'001];
const ll MOD = 1e9+9;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[0] = dp[1] = 1;
    dp[2] = dp[3] = 2;
    dp[4] = dp[5] = 3;
    REP(i,6,100'000){
        dp[i] = (dp[i-2] + dp[i-4] + dp[i-6])%MOD;
    }
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<dp[n]<<'\n';
    }
}