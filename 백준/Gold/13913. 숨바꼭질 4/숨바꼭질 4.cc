#include<bits/stdc++.h>
using namespace std;
int way[100001];
int dist[100001];
vector<int> path;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n,m; //n:수빈, m:동생
	cin>>n>>m;
	fill(dist,dist+100001,-1);
	queue<int> Q;
	dist[n]=0;
	Q.push(n);
	
	while(dist[m]==-1){
		int cur = Q.front(); Q.pop();
		for(int nxt:{cur-1,cur+1,cur*2}){
			if(nxt<0||nxt>100000) continue; // 범위 초과
			if(dist[nxt]!=-1) continue; // 이미 들른 곳
			dist[nxt] = dist[cur]+1;
			way[nxt] = cur;
			Q.push(nxt);
		}
		// for(int i=0;i<30;i++){
		// 	cout<<way[i]<<" ";
		// }
		// cout<<"\n";
	}
	
	
	cout<<dist[m]<<'\n';
	
	int cur = m;
	while(cur!=n){
		path.push_back(cur);
		cur=way[cur];
	}
	path.push_back(n);
	
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
}