#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<pii> adj[10'001];
vector<pii> radj[10'001];
int deg[10'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        radj[e].push_back({x,s});
        deg[e]++;
    }
    int st,en; cin>>st>>en;

    vector<int> dist(n+1,0);
    queue<pii> q;
    vector<set<int>> parent(n+1);
    q.push({0,st});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur.Y]){
            dist[nxt.Y] = max(dist[nxt.Y], dist[cur.Y] + nxt.X);
            if(--deg[nxt.Y]) continue;
            q.push({dist[cur.Y]+nxt.X, nxt.Y});
        }
    }

    vector<int> vis(n+1,0);
    queue<int> qq;
    qq.push(en);
    vis[en] = 1;
    int cnt = 0;
    while(!qq.empty()){
        auto cur = qq.front(); qq.pop();
        for(auto nxt : radj[cur]){
            if(dist[cur]-nxt.X!=dist[nxt.Y]) continue;
            cnt++;
            if(vis[nxt.Y]) continue;
            vis[nxt.Y]=1;
            qq.push(nxt.Y);
        }
    }
    

    cout<<dist[en]<<'\n'<<cnt<<'\n';

}