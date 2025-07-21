import java.util.*;
class Solution {
    public int solution(int[][] beginning, int[][] target) {
        int n = beginning.length;
        int m = beginning[0].length;
        
        int ans = Integer.MAX_VALUE;
        for(int row=0; row<(1<<n); row++) for(int col=0; col<(1<<m); col++){
            int[][] board = new int[n][m];
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) board[i][j] = beginning[i][j];
            
            int cnt = 0;
            for(int i=0;i<n;i++){
                if((row&(1<<i))!=(1<<i)) continue;
                cnt++;
                for(int j=0;j<m;j++) board[i][j]^=1;
            }
            for(int i=0;i<m;i++){
                if((col&(1<<i))!=(1<<i)) continue;
                cnt++;
                for(int j=0;j<n;j++) board[j][i]^=1;
            }
            
            boolean flag = true;
            for(int i=0;i<n;i++) for(int j=0;j<m;j++){
                if(board[i][j]!=target[i][j]) flag = false;
            }
            
            if(flag){
                ans = Math.min(ans, cnt);
            }
        }

        
        return ans==Integer.MAX_VALUE ? -1: ans;
    }
}