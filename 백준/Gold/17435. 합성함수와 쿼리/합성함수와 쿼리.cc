#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/


int dp[200'001][20];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin>>m;
    rep(i,1,m+1) cin>>dp[i][0];

    rep(i,1,20){
        rep(j,1,m+1){
            dp[j][i]  = dp[dp[j][i-1]][i-1];
        }
    }

    int q; cin>>q;
    while(q--){
        int n,x; cin>>n>>x;
        for(int i=20;i>=0;i--){
            if(n&(1<<i)){
                x = dp[x][i];
            }
        }
        cout<<x<<'\n';
    }
}