#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const int MX = 100;
int dist[MX+1][MX+1][2];
int n;
bool OOB(pair<int,int> loc){
    return (loc.first<0||loc.first>=n||loc.second<0||loc.second>=n);
}
int solution(vector<vector<int>> board) {
    n = board.size();
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dist[i][j][0] = dist[i][j][1] = 2e9;
    
    queue<tuple<int,int,int>> q; 
    dist[0][0][0] = 0;
    q.push({0,0,0});
    while(!q.empty()){
        auto [x,y,d] = q.front(); q.pop();
        int px = x + (d!=0);
        int py = y + (d==0);
        //회전 X
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int pnx = px + dx[dir];
            int pny = py + dy[dir];
            if(OOB({nx,ny}) || OOB({pnx,pny})) continue;
            if(board[nx][ny] || board[pnx][pny]) continue;
            if(dist[nx][ny][d]!=2e9) continue;
            dist[nx][ny][d] = dist[x][y][d] + 1;
            q.push({nx,ny,d});
        }
        
        //회전 O
        //일단 회전 먼저
        int nx = (d==0 ? x-1:x);
        int ny = (d==0 ? y:y-1);
        int pnx = x;
        int pny = y;
        if(d==0){
            if(!OOB({nx,ny}) && !OOB({nx,ny+1}) && !board[nx][ny] && !board[nx][ny+1]){
                if(dist[nx][ny][1]==2e9){
                    dist[nx][ny][1] = dist[x][y][0] + 1;
                    q.push({nx,ny,1});
                }
                if(dist[nx][ny+1][1]==2e9){
                    dist[nx][ny+1][1] = dist[x][y][0] + 1;
                    q.push({nx,ny+1,1});
                }
            }
            if(!OOB({nx+2,ny}) && !OOB({nx+2,ny+1}) && !board[nx+2][ny] && !board[nx+2][ny+1]){
                if(dist[nx+1][ny][1]==2e9){
                    dist[nx+1][ny][1] = dist[x][y][0] + 1;
                    q.push({nx+1,ny,1});
                }
                if(dist[nx+1][ny+1][1]==2e9){
                    dist[nx+1][ny+1][1] = dist[x][y][0] + 1;
                    q.push({nx+1,ny+1,1});
                }
            }
        }
        else{
            if(!OOB({nx,ny}) && !OOB({nx+1,ny}) && !board[nx][ny] && !board[nx+1][ny]){
                if(dist[nx][ny][0]==2e9){
                    dist[nx][ny][0] = dist[x][y][1] + 1;
                    q.push({nx,ny,0});
                }
                if(dist[nx+1][ny][0]==2e9){
                    dist[nx+1][ny][0] = dist[x][y][1] + 1;
                    q.push({nx+1,ny,0});
                }
            }
            if(!OOB({nx,ny+2}) && !OOB({nx+1,ny+2}) && !board[nx][ny+2] && !board[nx+1][ny+2]){
                if(dist[nx][ny+1][0]==2e9){
                    dist[nx][ny+1][0] = dist[x][y][1] + 1;
                    q.push({nx,ny+1,0});
                }
                if(dist[nx+1][ny+1][0]==2e9){
                    dist[nx+1][ny+1][0] = dist[x][y][1] + 1;
                    q.push({nx+1,ny+1,0});
                }
            }
        }

    }
    
    int ans = min(dist[n-1][n-2][0], dist[n-2][n-1][1]);
    return ans;
}