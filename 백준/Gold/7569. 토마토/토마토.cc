#include<bits/stdc++.h>
#include<tuple>
using namespace std;
// #define X get<0>(Q.front())
// #define Y get<1>(Q.front())
// #define Z get<2>(Q.front())
int board[102][102][102];
int dist[102][102][102]; // 거리 저장
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	queue<tuple<int,int,int>> Q;
	int n,m,l;
	cin>>l>>m>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<l;k++){
				cin>>board[i][j][k];
				if(board[i][j][k]==1){ //익은 토마토가 있을 때
					Q.push({i,j,k});
				}
				if(board[i][j][k]==0){ //덜 익은 토마토가 있을 때
					dist[i][j][k] = -1;
				}
			}

		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<vis[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir=0;dir<6;dir++){
			int x,y,z;
			tie(x,y,z) = cur;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];
			if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=l) continue; // 보드의 바깥
			if(dist[nx][ny][nz]>=0) continue; // 이미 방문함
			dist[nx][ny][nz] = dist[x][y][z]+1;
			Q.push({nx,ny,nz});
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<dist[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<l;k++){
				if(dist[i][j][k]==-1){
					cout<<-1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	
	cout<<ans;
}