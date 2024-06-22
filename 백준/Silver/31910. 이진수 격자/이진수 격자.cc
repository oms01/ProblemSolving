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
int dx[] = {0,0,1,-1}; 
int dy[] = {1,-1,0,0};
/*----------------------*/

ll board[31][31];
ll n;
ll ans;
ll val[31][31];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i,0,n) rep(j,0,n) cin>>board[i][j];

    rep(i,1,n) board[i][0] += board[i-1][0]<<1;
    rep(i,1,n) board[0][i] += board[0][i-1]<<1;

    rep(i,1,n)rep(j,1,n) board[i][j] += max(board[i-1][j]<<1, board[i][j-1]<<1); 
    cout<<board[n-1][n-1]<<'\n';


}
