import java.util.*;

class Solution {
    int[] dx = {0,0,1,-1};
    int[] dy = {1,-1,0,0};
    int[][][] dist = new int[30][30][5];
    
    static class Loc{
        int x, y, dir, cost;
        Loc(int x,int y,int dir, int cost){
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.cost = cost;
        }
    }
        
        
    public int solution(int[][] board) {
        int n = board.length;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<5;k++){
            dist[i][j][k] = Integer.MAX_VALUE;
        }
        Queue<Loc> q = new LinkedList<>();
        for(int i=0;i<4;i++) dist[0][0][i] = 0;
        q.offer(new Loc(0,0,-1,0));
        while(!q.isEmpty()){
            Loc cur = q.poll();
            for(int dir=0;dir<4;dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(board[nx][ny]==1) continue;
                
                int cost = cur.cost + 100;
                if(dir!=-1 && dir!=cur.dir) cost+=500;
                
                if(dist[nx][ny][dir] < cost) continue;
                dist[nx][ny][dir] = cost;
                q.offer(new Loc(nx,ny,dir,cost));
            }
        }
        
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<5;i++) ans = Math.min(ans, dist[n-1][n-1][i]);
        return ans-500;
    }
}