import java.util.*;
class Solution {
    
    int[] dx = {0,0,1,-1};
    int[] dy = {1,-1,0,0};
    int[][][] dist = new int[101][101][2];
    int n;
    boolean OOB(int x, int y){
        return (x<0||x>=n||y<0||y>=n);
    }
    
    public int solution(int[][] board) {
        n = board.length;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) dist[i][j][0] = dist[i][j][1] = Integer.MAX_VALUE;
        
        Queue<int[]> q = new LinkedList<>();
        dist[0][0][0] = 0;
        q.add(new int[]{0,0,0});
        while(!q.isEmpty()){
            int[] tmp = q.poll();
            int x = tmp[0];
            int y = tmp[1];
            int d = tmp[2];
            int px = x + (d==0?0:1);
            int py = y + (d==0?1:0);
            
            Vector<int[]> nxts = new Vector<>();
            
            //회전 X
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int pnx = px + dx[dir];
                int pny = py + dy[dir];
                if(OOB(nx,ny) || OOB(pnx,pny)) continue;
                if(board[nx][ny]==1 || board[pnx][pny]==1) continue;
                nxts.add(new int[]{nx,ny,d});
            }
            
            //회전 O
            int nx = (d==0 ? x-1:x);
            int ny = (d==0 ? y:y-1);
            if(d==0){
                if(!OOB(nx,ny) && !OOB(nx,ny+1) && board[nx][ny]==0 && board[nx][ny+1]==0){
                    nxts.add(new int[]{nx,ny,1});
                    nxts.add(new int[]{nx,ny+1,1});
                }
                if(!OOB(nx+2,ny) && !OOB(nx+2,ny+1) && board[nx+2][ny]==0 && board[nx+2][ny+1]==0){
                    nxts.add(new int[]{nx+1,ny,1});
                    nxts.add(new int[]{nx+1,ny+1,1});
                }
            }
            else{
                if(!OOB(nx,ny) && !OOB(nx+1,ny) && board[nx][ny]==0 && board[nx+1][ny]==0){
                    nxts.add(new int[]{nx,ny,0});
                    nxts.add(new int[]{nx+1,ny,0});
                }
                if(!OOB(nx,ny+2) && !OOB(nx+1,ny+2) && board[nx][ny+2]==0 && board[nx+1][ny+2]==0){
                    nxts.add(new int[]{nx,ny+1,0});
                    nxts.add(new int[]{nx+1,ny+1,0});
                }
            }
            
            
            for(int[] cur: nxts){
                if(dist[cur[0]][cur[1]][cur[2]]!=Integer.MAX_VALUE) continue;
                dist[cur[0]][cur[1]][cur[2]] = dist[x][y][d] + 1;
                q.add(cur);
            }
        }
        
        
        return Math.min(dist[n-1][n-2][0], dist[n-2][n-1][1]);
    }
}