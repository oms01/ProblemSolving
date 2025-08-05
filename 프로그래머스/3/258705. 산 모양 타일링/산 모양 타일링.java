class Solution {
    public int solution(int n, int[] tops) {
        
        int[] dp = new int[200_002];
        dp[0] = 1;
        dp[1] = tops[0]==0 ? 2: 3;
        
        for(int i=2;i<=2*n;i++){
            if(i%2==1 && tops[(i-1)/2]==1){
                dp[i] = dp[i-1]*2 + dp[i-2];
            }
            else{
                dp[i] = dp[i-1] + dp[i-2];
            }
            dp[i] %= 10_007;
        }
        
        return dp[2*n];
    }
}