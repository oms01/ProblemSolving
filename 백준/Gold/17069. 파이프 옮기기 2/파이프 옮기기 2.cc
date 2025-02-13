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

const int MX = 50;
ll board[MX+1][MX+1];
ll dp[MX+1][MX+1][3]; // i,j칸에 k방향으로 파이프 놓여지는 경우
//k = 0,1,2 :  →, ↘, ↓
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    REP(i,1,n) REP(j,1,n) cin>>board[i][j];

    dp[1][2][0] = 1;

    REP(i,1,n){
        REP(j,1,n){
            if(i==1&&(j==1||j==2)) continue;
            if(board[i][j]) continue;
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
            dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];

            if(board[i-1][j]||board[i][j-1]) continue;
            dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }

    cout<<dp[n][n][0]+dp[n][n][1]+dp[n][n][2]<<'\n';
}