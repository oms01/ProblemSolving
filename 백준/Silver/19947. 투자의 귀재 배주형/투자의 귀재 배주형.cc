#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
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

int dp[11];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int y;
    cin>>dp[0]>>y;
    
    for(int i=1;i<=y;i++){
        dp[i] = max(dp[i], dp[i-1]*21/20);
        if(i>=3) dp[i] = max(dp[i], dp[i-3]*6/5);
        if(i>=5) dp[i] = max(dp[i], dp[i-5]*27/20);
    }
    cout<<dp[y]<<'\n';
}