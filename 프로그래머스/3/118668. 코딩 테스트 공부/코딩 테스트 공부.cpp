#include <bits/stdc++.h>
using namespace std;

const int MX = 150;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int dp[MX+1][MX+1];
    for(int i=0;i<=MX;i++) for(int j=0;j<=MX;j++) dp[i][j] = 2e9;
    dp[alp][cop] = 0;
    
    for(int i=alp;i<=MX;i++) for(int j=cop;j<=MX;j++){
        if(i+1<=MX) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
        if(j+1<=MX) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
        
        for(auto cur: problems){
            int alp_req = cur[0], cop_req = cur[1];
            int alp_rwd = cur[2], cop_rwd = cur[3];
            int cost = cur[4];
            
            if(i<alp_req || j<cop_req) continue;
            int nxt_alp = min(MX, i + alp_rwd);
            int nxt_cop = min(MX, j + cop_rwd);
            dp[nxt_alp][nxt_cop] = min(dp[nxt_alp][nxt_cop], dp[i][j] + cost);
        }
    }
    
    int mx_alp = alp;
    int mx_cop = cop;
    for(auto cur: problems){
        mx_alp = max(mx_alp, cur[0]);
        mx_cop = max(mx_cop, cur[1]);
    }
    
    
    int ans = 2e9;
    for(int i=mx_alp;i<=MX;i++) for(int j=mx_cop;j<=MX;j++){
        ans = min(ans, dp[i][j]);
    }
    return ans;
}