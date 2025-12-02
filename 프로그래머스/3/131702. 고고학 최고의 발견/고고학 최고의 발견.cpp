#include <bits/stdc++.h>
using namespace std;

int n;
void rotate(vector<vector<int>> &board, int x, int y){
    int dx[] = {0,0,0,1,-1};
    int dy[] = {0,1,-1,0,0};
    for(int dir=0;dir<5;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        board[nx][ny] = (board[nx][ny]+1)%4;
    }
}
int solution(vector<vector<int>> clockHands) {
    n = clockHands.size();
    
    int ans = 2e9;
    for(int brute=0;brute<(1<<(2*n));brute++){
        int cur = 0;
        int tmp = brute;
        auto board = clockHands;
        
        //맨 윗줄 설정
        for(int i=0;i<n;i++){
            int cnt = tmp%4;
            cur+=cnt;
            while(cnt--) rotate(board, 0, i);
            tmp/=4;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt = (4-board[i-1][j])%4;
                cur+=cnt;
                while(cnt--) rotate(board, i, j);
            }
        }
        
        bool flag = 1;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]) flag = 0;
        if(flag) ans = min(ans, cur);
        
    }
    
    return ans;
}