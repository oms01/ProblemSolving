#include <bits/stdc++.h>
#define X first
#define Y second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
using namespace std;

vector<vector<int>> board;
int vis[501][501];
int n,m;
map<int,int> ma;
void bfs(int no, int x, int y){ //뭉치 번호, 현재 위치
    int cnt = 1;
    board[x][y] = no;
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]==0) continue;
            if(vis[nx][ny]) continue;
            
            cnt++;
            board[nx][ny] = no;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    ma[no] = cnt;
    return;
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    
    int answer = 0;
    int num = 1;
    board = land;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0) continue;
            if(vis[i][j]) continue;
            bfs(num, i, j);
            num++;
        }
    }
    int mx=0;
    for(int i=0;i<m;i++){
        set<int> s;
        int tmp = 0;
        for(int j=0;j<n;j++){
            if(board[j][i]==0) continue;
            s.insert(board[j][i]);
        }
        for(auto x:s){
            tmp+=ma[x];
        }
        mx = max(mx,tmp);
    }
    
    return mx;
}