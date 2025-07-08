class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        
        int[][] dist = new int[201][201];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            dist[i][j] = (i==j?0:100_000_000);
        }
        
        for(int[] v: fares){
            int st = v[0]-1;
            int en = v[1]-1;
            int cost = v[2];
            dist[st][en] = dist[en][st] = cost;
        }
        
        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            dist[i][j] = Math.min(dist[i][j], dist[i][k]+dist[k][j]);
        }
        
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            ans = Math.min(ans, dist[s-1][i] + dist[i][a-1] + dist[i][b-1]);
        }
        return ans;
    }
}