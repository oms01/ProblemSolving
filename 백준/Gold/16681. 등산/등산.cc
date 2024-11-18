#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
const ll INF = 2e14;
vector<pll> adj[100'001];
ll height[100'001];
ll n,m,d,e;
vector<ll> dijkstra(ll st){
    vector<ll> d(100'001,INF);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y]!=cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y]<=d[cur.Y]+nxt.X) continue;
            if(height[nxt.Y] <= height[cur.Y]) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    return d;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>d>>e;
    rep(i,1,n+1) cin>>height[i];

    rep(i,0,m){
        ll st,en,x; cin>>st>>en>>x;
        adj[st].push_back({x,en});
        adj[en].push_back({x,st});
    }

    vector<ll> stDist = dijkstra(1);
    vector<ll> enDist = dijkstra(n);
    ll ans = -INF;
    rep(i,1,n+1){
        if(stDist[i]==INF || enDist[i]==INF) continue;
        ll dist = stDist[i] + enDist[i];
        ll h = height[i];
        ans = max(ans, h*e - dist*d);
    }

    if(ans==-INF){
        cout<<"Impossible\n";
    }
    else{
        cout<<ans<<'\n';
    }
}
