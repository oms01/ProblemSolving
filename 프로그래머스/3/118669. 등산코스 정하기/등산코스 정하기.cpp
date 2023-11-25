#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int,int> pii;
int dist[50001];
bool summ[50001];
vector<pii> adj[50001];
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    vector<pii> v;
    for(auto x:summits) summ[x] = 1;
    fill(dist,dist+50001,2e9);
    for(auto x:paths){
        adj[x[0]].push_back({x[2],x[1]});
        adj[x[1]].push_back({x[2],x[0]});
    }
    
    
    priority_queue<pii,vector<pii>, greater<pii>> pq; //가중치, 도착점
    for(auto x: gates){
        pq.push({0,x});
        dist[x]=0;
    }
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.X > dist[cur.Y]) continue;
        if(summ[cur.Y]){
            v.push_back(cur);
            continue;
        }
        
        for(auto nxt: adj[cur.Y]){
            if(dist[nxt.Y]==2e9 || max(cur.X, nxt.X) < dist[nxt.Y]){
                dist[nxt.Y] = max(cur.X,nxt.X);
                pq.push({dist[nxt.Y],nxt.Y});
            }
        }
        
    }
    sort(v.begin(),v.end());
    tie(answer[1],answer[0]) = v[0];
    return answer;
}