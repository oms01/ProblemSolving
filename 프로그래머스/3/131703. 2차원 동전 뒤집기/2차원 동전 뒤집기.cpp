#include <bits/stdc++.h>
using namespace std;

int n,m;
void colSwap(vector<vector<int>>& board, int c){
    for(int i=0;i<n;i++){
        board[i][c] ^= 1;
    }
}
void rowSwap(vector<vector<int>>& board, int r){
    for(int i=0;i<m;i++){
        board[r][i] ^= 1;
    }
}
bool chk(vector<vector<int>>& board, vector<vector<int>>& target){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(board[i][j]!=target[i][j]) return 0;
    }
    return 1;
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    n = beginning.size();
    m = beginning[0].size();    
    
    int ans = 2e9;
    for(int brute = 0; brute < (1<<(n+m)); brute++){
        auto board = beginning;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if((brute & (1<<i))==(1<<i)){
                cnt++;
                rowSwap(board,i);
            }
        }
        for(int i=n;i<n+m;i++){
            if((brute & (1<<i))==(1<<i)){
                cnt++;
                colSwap(board,i-n);
            }
        }
        if(chk(board, target)){
            ans = min(ans, cnt);
        }
        
    }
    
    return ans==2e9 ? -1 : ans;
}