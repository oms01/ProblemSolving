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

const int MX = 100'000;
ll dp[MX+1][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n,0); rep(i,0,n) cin>>v[i];

    dp[0][0] = 0;
    dp[0][1] = v[0];

    rep(i,1,n){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][1],dp[i-1][0])+v[i];
    }

    cout<<min(dp[n-1][0],dp[n-1][1])<<'\n';

    
}