import java.util.*;

class Solution {
    int MX = 150;
    int INF = 100_000_000;
    public int solution(int alp, int cop, int[][] problems) {
        int n = problems.length;
        
        int mx_alp = alp;
        int mx_cop = cop;
        for(int[] cur: problems){
            mx_alp = Math.max(mx_alp, cur[0]);
            mx_cop = Math.max(mx_cop, cur[1]);
        }
        
        int[][] dp = new int[MX+1][MX+1];
        for(int i=0;i<=MX;i++) for(int j=0;j<=MX;j++) dp[i][j] = INF;
        dp[alp][cop] = 0;
        
        for(int i=alp;i<=MX;i++) for(int j=cop;j<=MX;j++){
            if(i+1<=MX) dp[i+1][j] = Math.min(dp[i+1][j], dp[i][j]+1);
            if(j+1<=MX) dp[i][j+1] = Math.min(dp[i][j+1], dp[i][j]+1);
            
            for(int[] cur: problems){
                int alp_req = cur[0];
                int cop_req = cur[1];
                int alp_rwd = cur[2];
                int cop_rwd = cur[3];
                int cost = cur[4];
                
                if(i<alp_req || j<cop_req) continue;
                int nxt_alp = Math.min(MX, i+alp_rwd);
                int nxt_cop = Math.min(MX, j+cop_rwd);
                dp[nxt_alp][nxt_cop] = Math.min(dp[nxt_alp][nxt_cop], dp[i][j]+cost);

            }
        }

        int ans = INF;
        for(int i=mx_alp;i<MX+1;i++) for(int j=mx_cop;j<MX+1;j++){
            ans = Math.min(ans, dp[i][j]);
        }
        
        return ans;
    }
}