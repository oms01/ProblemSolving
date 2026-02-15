import java.io.*;
import java.util.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
    static final int MX = 20;
    static int[][] board = new int[MX][MX];
    static int[][][] dp = new int[MX][MX][3]; //i,j칸에 k방향으로 파이프를 놓는 경우의수
    
	public static void main(String args[]) throws Exception{
		int n = Integer.parseInt(br.readLine());
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=n;j++) board[i][j] = Integer.parseInt(st.nextToken());
        }

        dp[1][2][0] = 1;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            if(i==1&&(j==1||j==2)) continue;
            if(board[i][j]!=0) continue;
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
            dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];

            if(board[i-1][j]==0 && board[i][j-1]==0){
                dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
        sb.append(dp[n][n][0] + dp[n][n][1] + dp[n][n][2]);
		bw.write(sb.toString());
		bw.flush();
    }

}