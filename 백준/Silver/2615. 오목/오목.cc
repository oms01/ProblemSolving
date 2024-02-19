#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
int n,m,t;
vector<pair<int,int>> black;
vector<pair<int,int>> white;
int board[20][20];
int vis[20][20];
vector<pair<int,int>> ans(2); //0:검정, 1:하양
bool horizontal(int x,int y){ //가로
	int cnt = 1;
	for(int i=1;i<=19;i++){
		if(y+i>19) break;
		if(vis[x][y+i] || board[x][y+i]!=board[x][y]) break;
		cnt++;
		vis[x][y+i]=1;
	}
	if(cnt==5) ans[board[x][y]-1] = {x,y};
	return cnt==5;
}
bool vertical(int x,int y){ //세로 
	int cnt = 1;
	for(int i=1;i<=19;i++){
		if(x+i>19) break;
		if(vis[x+i][y] || board[x+i][y]!=board[x][y]) break;
		cnt++;
		vis[x+i][y]=1;
	}
	if(cnt==5) ans[board[x][y]-1] = {x,y};
	return cnt==5;
}
bool diagonal1(int x,int y){ //대각선
	int cnt = 1;
	for(int i=1;i<=19;i++){
		if(x+i>19 || y+i>19) break;
		if(vis[x+i][y+i] || board[x+i][y+i]!=board[x][y]) break;
		cnt++;
		vis[x+i][y+i]=1;
	}
	if(cnt==5) ans[board[x][y]-1] = {x,y};
	return cnt==5;
}
bool diagonal2(int x,int y){ //대각선
	int cnt = 1;
	//cout<<x<<" "<<y<<"\n";
	for(int i=1;i<=19;i++){
		//cout<<x-i<<" "<<y+i<<"\n";
		if(x-i<=0 || y+i>19) break;
		if(vis[x-i][y+i] || board[x-i][y+i]!=board[x][y]) break;
		cnt++;
		vis[x-i][y+i]=1;
	}
	//cout<<cnt<<'\n';
	if(cnt==5) ans[board[x][y]-1] = {x,y};
	return cnt==5;
}
bool chk(const vector<pair<int, int>>& v){
	bool flag = 0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<v.size();i++){
		int x = v[i].X, y = v[i].Y;
		if(vis[x][y]) continue;
		flag |= horizontal(x,y);
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<v.size();i++){
		int x = v[i].X, y = v[i].Y;
		if(vis[x][y]) continue;
		flag |= vertical(x,y);
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<v.size();i++){
		int x = v[i].X, y = v[i].Y;
		if(vis[x][y]) continue;
		flag |= diagonal1(x,y);
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<v.size();i++){
		int x = v[i].X, y = v[i].Y;
		if(vis[x][y]) continue;
		flag |= diagonal2(x,y);
	}
	return flag;
}
bool compare(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=1;i<=19;i++){
		for(int j=1;j<=19;j++){
			cin>>board[i][j];
			if(board[i][j]==1) black.push_back({i,j});
			if(board[i][j]==2) white.push_back({i,j});
		}
	}
	sort(black.begin(),black.end(),compare);
	sort(white.begin(),white.end(),compare);
	bool bwin = chk(black);
	bool wwin = chk(white);

	if(bwin==0 &&wwin==0) cout<<0<<'\n';
	else if(bwin){
		cout<<1<<'\n';
		cout<<ans[0].first<<" "<<ans[0].second<<'\n';
	}
	else if(wwin){
		cout<<2<<'\n';
		cout<<ans[1].first<<" "<<ans[1].second<<'\n';
	}
}
/*

*/