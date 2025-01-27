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

ll dp[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    fill(dp,dp+1001,2e9);
    int n; cin>>n;
    REP(i,1,n) cin>>dp[i];
    dp[0] = 0;

    REP(i,1,n){
        REP(j,1,n){
            if(i-j >= 0) dp[i] = min(dp[i],dp[i-j] + dp[j]);
        }
    }
    cout<<dp[n]<<'\n';

}