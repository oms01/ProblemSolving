#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef pair<int,int> pii;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int n;
int dist[30][30][5];
int solution(vector<vector<int>> board) {
    int answer = 2e9;
    n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fill(dist[i][j],dist[i][j]+30,2e9);
        }
    }
    queue<tuple<int,int,int,int>> q;
    for(int i=0;i<4;i++) dist[0][0][i] = 0;
    q.push({0,0,-1,0});
    while(!q.empty()){
        pii cur;
        int d,pay;
        tie(cur.X,cur.Y,d,pay) = q.front(); q.pop();
        if(cur.X==n-1&&cur.Y==n-1){
            answer = min(answer,dist[cur.X][cur.Y][d]);
            continue;
        }
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(board[nx][ny]) continue;

            int tmp = 100;
            if(d!=dir && d!=-1) tmp+=500;
            
            if(dist[nx][ny][dir] < pay+tmp) continue;
            dist[nx][ny][dir] = pay + tmp;
            q.push({nx,ny,dir,pay + tmp});
            
        }
    }
    return answer;
}