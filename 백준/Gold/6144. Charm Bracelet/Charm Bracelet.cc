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

int dp[45001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,1,n+1){
        int a,b; cin>>a>>b;
        for(int j=m;j>=a;j--){
            dp[j] = max(dp[j], dp[j-a]+b);
        }
    }
    cout<<dp[m];

}
