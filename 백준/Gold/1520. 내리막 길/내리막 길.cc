#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
int board[501][501];
int vis[501][501];
int dp[501][501];
int func(int x,int y){
    if(x==n-1&&y==m-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y] = 0;
    pair<int,int> cur = {x,y};
    for(int dir=0;dir<4;dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) continue; //범위 밖
        if(board[cur.X][cur.Y] <= board[nx][ny]) continue; //오르막
        dp[x][y] += func(nx,ny);
    }
    return dp[x][y];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        fill(dp[i],dp[i]+m,-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>board[i][j];
    }
    cout<<func(0,0);
}