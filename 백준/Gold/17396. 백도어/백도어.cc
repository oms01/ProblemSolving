#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e16;
ll d[300'001];
vector<pair<ll,ll>> adj[300'001];
ll n,m;
bool board[300'001];
void dijkstra(int st){
    fill(d,d+n+1,INF);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }

    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        if((board[u]&&u!=n-1) || (board[v]&&v!=n-1)) continue;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    dijkstra(0);
    cout<<(d[n-1]==2e16 ? -1 : d[n-1]);
}