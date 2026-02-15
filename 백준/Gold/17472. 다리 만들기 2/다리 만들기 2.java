import java.io.*;
import java.util.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
    static final int MX = 100;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    static int[][] board = new int[MX][MX];
    static int[][] vis = new int[MX][MX];
    static ArrayList<int[]> adj = new ArrayList<>();
    static int n,m,k;
    static int ans;

    static class UF{
        int MX = 7;
        int[] p = new int[MX];
        UF(){
            for(int i=0;i<MX;i++) p[i] = i;
        }
        int find(int a){
            if(p[a]==a) return a;
            return p[a] = find(p[a]);
        }
        void union(int a, int b){
            a = find(a); b = find(b);
            if(a!=b) p[a] = b;
        }
    }
    
	public static void main(String args[]) throws Exception{
        st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++) board[i][j] = Integer.parseInt(st.nextToken())*-1;
        }

        k = 0; //섬의 개수
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(board[i][j]==0 || vis[i][j]==1) continue;
            bfs(i,j,++k);
        }

        //다리 후보 저장
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(board[i][j]==0) continue;
            for(int dir=0;dir<4;dir++){
                f(i,j,board[i][j], dir, 0);
            }
        }
        
		bw.write(String.valueOf(kruskal()));
		bw.flush();
    }

    public static void bfs(int x, int y, int idx){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x,y});
        vis[x][y] = 1;
        board[x][y] = idx;
        while(!q.isEmpty()){
            int[] cur = q.poll();
            for(int dir=0;dir<4;dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(vis[nx][ny]!=0 || board[nx][ny]==0) continue;
                board[nx][ny] = idx;
                vis[nx][ny] = 1;
                q.add(new int[]{nx,ny});
            }
        }
    }

    public static void f(int x, int y, int num, int dir, int dist){
        if(board[x][y]!=num && board[x][y]!=0){
            if(dist<=2) return;
            adj.add(new int[]{dist-1, num, board[x][y]});
            return;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) return;
        if(board[nx][ny]==num) return;
        f(nx,ny,num,dir,dist+1);
    }

    public static int kruskal(){
        UF uf = new UF();
        Collections.sort(adj,(o1,o2)->o1[0]-o2[0]);

        int ans = 0;
        int cnt = 0;
        for(int[] e: adj){
            int c = e[0], st = e[1], en = e[2];
            if(uf.find(st)==uf.find(en)) continue;
            uf.union(st,en);
            ans += c;
            cnt++;
            if(cnt==k-1) break;
        }

        return cnt!=k-1 ? -1 : ans;
    }
}