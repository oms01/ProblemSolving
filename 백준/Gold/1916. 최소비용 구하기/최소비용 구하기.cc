#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector<pair<int,int>> adj[1001]; // 비용, 정점번호
const int INF = 200000000;
int d[1001];
int res[1001];
int n,m;
void dijkstra(int k){
	priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	fill(d,d+n+1,INF);
	d[k]=0;
	pq.push({d[k],k});
	while(!pq.empty()){
		auto cur=pq.top(); pq.pop();
		if(d[cur.Y]!=cur.X) continue;
		for(auto nxt:adj[cur.Y]){
			if(d[nxt.Y]<=d[cur.Y]+nxt.X) continue;
			d[nxt.Y]=d[cur.Y]+nxt.X;
			pq.push({d[nxt.Y],nxt.Y});
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	fill(d,d+n+1,INF);
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({w,v});
	}
	int a,b;
	cin>>a>>b;
	
	dijkstra(a);
	// for(int i=1;i<=n;i++){
	// 	cout<<d[i]<<' ';
	// }
	// cout<<'\n';
	cout<<d[b];

}