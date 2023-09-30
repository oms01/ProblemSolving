#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string board[55];
int vis[55][55];
int n,m;
int sx,sy;
bool flag;
void dfs(int x,int y,int d){
    if(d>=4 && sx==x && sy==y){
        flag = 1;
        return;
    }
    for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(board[x][y] != board[nx][ny]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs(nx,ny,d+1);
        vis[nx][ny] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>board[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sx = i; sy = j;
            dfs(i,j,1);
            if(flag){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
}