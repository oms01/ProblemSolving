#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int dp[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    fill(dp,dp+100'001,2e9);

    int n,k; cin>>n>>k;
    dp[0] = 0;
    rep(i,0,n){
        int x; cin>>x;
        for(int i=k;i-x>=0;i--){
            dp[i] = min(dp[i],dp[i-x] + 1);
        }
    }
    cout<<(dp[k]==2e9 ? -1 : dp[k])<<'\n';
}