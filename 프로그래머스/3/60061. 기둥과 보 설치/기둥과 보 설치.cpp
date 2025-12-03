#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 111;
int board[MX+1][MX+1]; //빈칸 0, 기둥 1, 보 2 | 기둥은 위로, 보는 오른쪽으로
int n;

bool bo(int x, int y){
    return board[x][y-1]&1 || board[x+1][y-1]&1 || (board[x-1][y]&2 && board[x+1][y]&2);
}
bool gi(int x, int y){
    return y==1 || board[x][y-1]&1 || board[x-1][y]&2 || board[x][y]&2;
}
bool chk(int x, int y){
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n+1;j++){
            if(board[i][j]&1 && !gi(i,j)) return 0;
            if(board[i][j]&2 && !bo(i,j)) return 0; 
        }
    }
    return 1;
}

vector<vector<int>> solution(int N, vector<vector<int>> build_frame) {
    n = N+1;
    for(auto cur: build_frame){
        int x = cur[0]+1;
        int y = cur[1]+1; 
        int a = cur[2]; // 0이면 기둥, 1이면 보
        int b = cur[3]; // 0이면 삭제, 1이면 설치
        
        if(b){ //설치
            if(a && bo(x,y)){ //보
                board[x][y] |= 2;
            }
            if(!a && gi(x,y)){ //기둥
                board[x][y] |= 1;
            } 
        }
        else{ //삭제
            board[x][y]^=(a?2:1);
            if(!chk(x,y)) board[x][y]|=(a?2:1);
        }

    }
    
    vector<vector<int>> ans;
    for(int i=1;i<=n+1;i++) for(int j=1;j<=n+1;j++){
        if(board[i][j]&1) ans.push_back({i-1,j-1,0});
        if(board[i][j]&2) ans.push_back({i-1,j-1,1});
    }
    
    return ans;
}