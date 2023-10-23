#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int board[21][21];
int dist[21][21];
int vis[21][21];
int n;
pair<int,int> shark;
int sz = 2;
int cnt;
int ans;
vector<tuple<int,int,int>> feed; //거리, 좌표
bool find(){ //먹을 수 있는게 있는가?
    memset(dist,0,sizeof(dist));
    memset(vis,0,sizeof(vis));
    feed.clear();
    queue<pair<int,int>> q;
    q.push(shark);
    vis[shark.X][shark.Y] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] > sz) continue;
            vis[nx][ny] = 1;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            if(board[nx][ny]!=0 && board[nx][ny]<sz){
                feed.push_back({dist[nx][ny],nx,ny});
            }
            q.push({nx,ny});
        }
    }
    if(feed.empty()){
        //먹을게 없음
        return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                shark = {i,j};
            }
        }
    }
    while(find()){
        sort(feed.begin(),feed.end());
        int target, x, y;
        tie(target,x,y) = feed[0];
        cnt++;
        ans += dist[x][y];
        board[shark.X][shark.Y] = 0;
        shark = {x,y};
        board[shark.X][shark.Y] = 9;
    
        if(cnt >= sz){
            sz++;
            cnt=0;
        }
    }


    cout<<ans<<'\n';


}
