#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
int ans=2e9;
bool OOB(int x,int y){
    return (x<0||x>=n||y<0||y>=m);
}

int vis[101][101];

pair<int,int> slide(vector<string> board, int dir, int x,int y){
    while(!OOB(x,y) && board[x][y]!='D'){
        x += dx[dir];
        y += dy[dir];
    }
    return {x-dx[dir],y-dy[dir]};
}

int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    
    int x=-1, y=-1; //시작 위치
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='R'){
                x = i; y = j;
            }
        }
    }
    
    
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            pair<int,int> nxt = slide(board, dir, cur.X, cur.Y);
            if(vis[nxt.X][nxt.Y]>0) continue;
            
            if(board[nxt.X][nxt.Y]=='G'){
                ans = min(ans,vis[cur.X][cur.Y]);
            }
            vis[nxt.X][nxt.Y] = vis[cur.X][cur.Y]+1;
            q.push({nxt.X,nxt.Y});
            
        }
        
    }
    
    if(ans==2e9) return -1;    
    return ans;
}