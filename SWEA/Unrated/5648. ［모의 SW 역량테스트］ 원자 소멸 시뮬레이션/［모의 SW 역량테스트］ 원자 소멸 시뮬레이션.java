import java.io.*;
import java.util.*;

class Solution{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
	public static void main(String args[]) throws Exception{
		int t = Integer.parseInt(br.readLine());
		for(int i=1;i<=t;i++) solve(i);
		bw.write(sb.toString());
		bw.flush();
	}

    static class P{
        int x,y,dir,e;
        boolean dead;
        public P(int x,int y, int dir, int e){
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.e = e;
        }
    }

	static int[] dx = {0,0,-1,1};
	static int[] dy = {1,-1,0,0};

    static int n;
    static int[][] board = new int[4001][4001];
    static P[] dots = new P[1000];

	
	public static void solve(int tc) throws Exception {
		n = Integer.parseInt(br.readLine());

		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = (Integer.parseInt(st.nextToken()) + 1000)*2;
			int y = (Integer.parseInt(st.nextToken()) + 1000)*2;
			int dir = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			dots[i] = new P(x,y,dir,e);
		}
		
		int ans = 0;
		for(int t=0;t<=4000&&n>0;t++) {

            for(int i=0;i<n;i++){
                P dot = dots[i];
                dot.x += dx[dot.dir];
                dot.y += dy[dot.dir];
                if(dot.x<0||dot.x>4000||dot.y<0||dot.y>4000){
                    dot.dead = true;
                    continue;
                }
                board[dot.x][dot.y] += dot.e;
            }

			for(int i=0;i<n;i++){
                P dot = dots[i];
                if(dot.dead) continue;
                if(dot.e != board[dot.x][dot.y]){
                    ans += board[dot.x][dot.y];
                    dot.dead = true;
                }
                board[dot.x][dot.y] = 0;
            }

            int m = 0;
            for(int i=0;i<n;i++){
                if(!dots[i].dead) dots[m++] = dots[i];
            }
            n = m;
		}
		
		sb.append("#"+tc+" ").append(ans).append("\n");
 	}
}