#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
int input[101][101];
int board[101][101];
int vis[101][101];
int idx = 1;
vector<pii> adj[101];

bool chk[10];
void prim(){
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
	chk[1] = 1;
	for(auto nxt:adj[1]) pq.push({nxt.X,1,nxt.Y});
	int cnt = 0;
	ll ans = 0;
	while(cnt<idx-2){
		int cost,a,b;
		tie(cost,a,b) = pq.top(); pq.pop();
		if(chk[b]) continue;
		ans+=cost;
		chk[b] = 1;
		cnt++;
		for(auto nxt:adj[b]){
			if(!chk[nxt.Y]) pq.push({nxt.X,b,nxt.Y});
		}
	}
	if(ans>=1e9) cout<<-1<<'\n';
	else cout<<ans<<'\n';
	return;
}
void bfs(int x,int y){
	queue<pii> q;
	q.push({x,y});
	vis[x][y] = 1;
	board[x][y] = idx;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx<0||nx>=n||ny<0||ny>=m) continue;
			if(vis[nx][ny]) continue;
			if(input[nx][ny]==0) continue;
			vis[nx][ny] = 1;
			board[nx][ny] = idx;
			q.push({nx,ny});
		}
	}
	return;
}
void dfs(int x, int y, int i, int dir, int cnt){
	if(board[x][y]!=i && board[x][y]!=0){
		if(cnt<=2) return;
		adj[i].push_back({cnt-1,board[x][y]});
		return;
	}
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if(board[nx][ny]==i) return;
	if(nx<0||nx>=n||ny<0||ny>=m) return;

	dfs(nx,ny,i,dir,cnt+1);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	//입력
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>input[i][j];
	}

	//영역 구분
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]) continue;
			if(input[i][j]==0) continue;
			bfs(i,j);
			idx++;
		}
	}

	//다리 구하기
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]==0) continue;
			for(int dir=0;dir<4;dir++){
				dfs(i,j,board[i][j],dir,0);
			}
		}
	}


	for(int i=1;i<idx;i++){
		for(int j=1;j<idx;j++){
			if(i==j) continue;
			adj[i].push_back({1e9,j});
		}
	}
	prim();
	
}