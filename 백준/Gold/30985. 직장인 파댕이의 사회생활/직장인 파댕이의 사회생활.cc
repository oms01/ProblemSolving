#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
const int MX = 100'000;
vector<pll> adj[MX+1];
vector<ll> dijkstra(int st){
    priority_queue<pll, vector<pll>, greater<>> pq;
    vector<ll> dist(MX+1,2e16);
    dist[st] = 0;
    pq.push({dist[st],st});
    while(!pq.empty()){
        auto [c,cur] = pq.top(); pq.pop();
        if(dist[cur]!=c) continue;
        for(auto [d,nxt]: adj[cur]){
            if(dist[nxt] <= dist[cur]+d) continue;
            dist[nxt] = dist[cur]+d;
            pq.push({dist[nxt],nxt});
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n,m,k; cin>>n>>m>>k;
    rep(i,0,m){
        ll s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        adj[e].push_back({x,s});
    }
    vector<ll> elev(n+1);
    REP(i,1,n) cin>>elev[i];

    auto dist1 = dijkstra(1);
    auto dist2 = dijkstra(n);

    ll ans = 2e16;
    REP(i,1,n){
        if(elev[i]==-1) continue;
        //1층 1번방 -> 1층 i번방 -> n층 i번 방 -> n층 n번 방
        ll ret = dist1[i] + dist2[i] + ((k-1)*elev[i]);
        ans = min(ans,ret);
    }
    cout<<(ans==2e16?-1:ans)<<'\n';


}