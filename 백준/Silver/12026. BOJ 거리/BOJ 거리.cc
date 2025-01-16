#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

ll dp[1'001];
char nxtValue(char c){
    if(c=='B') return 'O';
    if(c=='O') return 'J';
    return 'B';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    string board; cin>>board;

    fill(dp,dp+1'001,2e9);
    dp[0] = 0;
    rep(i,0,n){
        rep(j,i+1,n){
            if(board[j] != nxtValue(board[i])) continue;
            dp[j] = min(dp[j],dp[i] + ((j-i)*(j-i)));
        }
    }
    cout<<(dp[n-1]==2e9 ? -1 : dp[n-1])<<'\n';
}
