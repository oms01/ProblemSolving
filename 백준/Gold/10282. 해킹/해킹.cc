#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e16;
ll d[300'001];
int n,dd,c;
vector<pair<ll,ll>> adj[300'001];
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

    int t;
    cin>>t;
    while(t--){
        memset(adj,0,sizeof(adj));
        cin>>n>>dd>>c;
        while(dd--){
            int a,b,s;
            cin>>a>>b>>s;
            adj[b].push_back({s,a});
        }
        dijkstra(c);
        ll cnt=0;
        ll time=0;
        for(int i=1;i<=n;i++){
            if(d[i]==2e16) continue;
            cnt++;
            time=max(time,d[i]);
        }
        cout<<cnt<<' '<<time<<'\n';
    }
}