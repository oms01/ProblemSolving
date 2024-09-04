#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n,m;
int vis[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<string> board;
int f(pair<int,int> s, pair<int,int> t){
    memset(vis,0,sizeof(vis));
    vis[s.X][s.Y] = 1;
    queue<pair<int,int>> q; q.push(s);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]||board[nx][ny]=='X') continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y]+1;
            q.push({nx,ny});
            
            if(nx==t.X && ny==t.Y){
                return vis[nx][ny]-1;
            }
        }
    }
    return -1;
    
}


int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    board = maps;
    
    pair<int,int> st;
    pair<int,int> lever;
    pair<int,int> en;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(maps[i][j]=='S') st = {i,j};
        if(maps[i][j]=='L') lever = {i,j};
        if(maps[i][j]=='E') en = {i,j};
    }
    
    int a = f(st,lever);
    int b = f(en,lever);
    
    if(a==-1||b==-1) return -1;
    return a+b;
    
    
    
}