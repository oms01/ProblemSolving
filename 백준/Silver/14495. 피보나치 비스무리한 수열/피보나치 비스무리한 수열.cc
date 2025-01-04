#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

ll dp[120];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    dp[1] = dp[2] = dp[3] = 1;
    rep(i,4,n+1){
        dp[i] = dp[i-1] + dp[i-3];
    }
    cout<<dp[n]<<'\n';
}