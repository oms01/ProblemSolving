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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int a[10][100'001];
int dp[100'001][10]; //i일에 j번 디저트를 먹을때 최대
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m; //n일 m개
    rep(i,0,m) rep(j,0,n) cin>>a[i][j];
    
    rep(i,0,m) dp[0][i] = a[i][0];
    rep(i,1,n){
        rep(j,0,m){
            rep(k,0,m){
                //i-1일에 j를 먹었고, i일에 k를 먹을때 만족도
                dp[i][k] = max(dp[i][k], dp[i-1][j] + (k==j ? a[k][i]/2 : a[k][i]));
            }
        }
    }
    cout<<*max_element(dp[n-1],dp[n-1]+m);
}
