#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string board[301];
int vis[301][301];
int n,m;
int a,b,c,d;
bool bfs(){
    queue<pair<int,int>> q;
    q.push({a-1,b-1});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = 1;
            if(board[nx][ny]=='#') return 1;
            else if(board[nx][ny]=='1'){
                board[nx][ny] = '0';
                continue;
            }
            q.push({nx,ny});
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>a>>b>>c>>d;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    queue<pair<int,int>> q;
    q.push({a-1,b-1});
    vis[a-1][b-1] = 1;
    int cnt=0;
    while(1){
        cnt++;
        memset(vis,0,sizeof(vis));
        if(bfs()) break;
    }
    cout<<cnt<<'\n';
    // cout<<vis[x1][y1];
}