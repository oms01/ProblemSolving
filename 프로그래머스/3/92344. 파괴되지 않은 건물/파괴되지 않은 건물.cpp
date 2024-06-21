#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size(); int m = board[0].size();
    vector<vector<int>> d(n+1,vector<int>(m+1,0));
    for(auto x : skill){
        int type = x[0]; int s1 = x[1]; int e1 = x[2];
        int s2 = x[3]; int e2 = x[4]; int k = x[5];
        if(type==1) k*=-1;
        d[s1][e1]+=k; d[s2+1][e2+1]+=k;
        d[s1][e2+1]-=k; d[s2+1][e1]-=k;
    }
    for(int i=0;i<n;i++) for(int j=1;j<m;j++) d[i][j]+=d[i][j-1];
    for(int i=0;i<n;i++) for(int j=1;j<m;j++) d[j][i]+=d[j-1][i];
    
    int ans = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
        ans += (d[i][j] + board[i][j]>0);
    
    return ans;
}