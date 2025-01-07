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
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(dp,dp+100'001,2e9);
    dp[1] = dp[2] = dp[5] = dp[7] = 1;
    
    int n; cin>>n;
    REP(i,1,100'000){
        dp[i] = min(dp[i],min({dp[max(0,i-1)], dp[max(0,i-2)], dp[max(0,i-5)], dp[max(0,i-7)]})+1);
    }
    dp[0] = 0;
    cout<<dp[n]<<'\n';
}