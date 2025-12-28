#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<int,int,int,int> ti4;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
/*----------------------*/

const int MX = 500;
int board[MX+1][MX+1];
int dp[MX+1][MX+1];
int n;
int f(int x,int y){
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    rep(dir,0,4){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(board[nx][ny] <= board[x][y]) continue;
        dp[x][y] = max(dp[x][y], f(nx,ny)+1);
    }
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i,0,n) rep(j,0,n) cin>>board[i][j];

    int ans = 1;
    rep(i,0,n) rep(j,0,n) ans = max(ans, f(i,j));
    cout<<ans<<'\n';
}
