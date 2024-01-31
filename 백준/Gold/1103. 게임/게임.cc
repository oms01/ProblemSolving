#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
string board[51];
int n,m;
int ans;
vector<vector<int>> vis(51,vector<int>(51));
int dp[51][51];
int func(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return 0;
	if(board[x][y]=='H') return 0;
	if(dp[x][y]) return dp[x][y];
	if(vis[x][y]){
		cout<<-1<<'\n';
		exit(0);
	}

	vis[x][y] = 1;
	int mx = -2e9;
	int val = board[x][y]-'0';
	for(int dir=0;dir<4;dir++){
		int nx = x + dx[dir]*val;
		int ny = y + dy[dir]*val;
		mx = max(mx,func(nx,ny)+1);
	}
	dp[x][y]=mx;
	vis[x][y]=0;
	return dp[x][y];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>board[i];
	}
	cout<<func(0,0);
}