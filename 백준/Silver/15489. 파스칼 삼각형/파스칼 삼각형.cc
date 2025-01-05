#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int dp[50][50];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    dp[1][1] = 1;
    rep(i,2,32) rep(j,1,i+1){
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }

    int r,c,w; cin>>r>>c>>w;

    int ans = 0;
    rep(i,0,w) rep(j,0,i+1){
        ans += dp[r+i][c+j];
    }

    cout<<ans<<'\n';

}