#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
ll dp[10'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    dp[0] = 1;
    rep(i,0,n){
        rep(j,v[i],m+1){
            dp[j] += dp[j-v[i]];
        }
    }
    cout<<dp[m]<<'\n';

}