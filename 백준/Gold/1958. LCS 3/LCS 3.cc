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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

/*----------------------*/
int dp[101][101][101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string a,b,c; cin>>a>>b>>c;
    
    REP(i,1,a.length()) REP(j,1,b.length()) REP(k,1,c.length()){
        if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
            dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        }
        else{
            dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
        }
    }
    cout<<dp[a.length()][b.length()][c.length()]<<'\n';
}