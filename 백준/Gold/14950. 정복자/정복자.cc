#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<pll> adj[10'001];
bool vis[10'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,t; cin>>n>>m>>t;
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        adj[e].push_back({x,s});
    }

    priority_queue<pll,vector<pll>, greater<>> pq;
    for(auto x: adj[1]) pq.push(x);
    vis[1] = 1;
    
    ll ans = 0;
    ll cnt = 1;
    while(cnt<n){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        ans += cur.X;
        cnt++;
        for(auto nxt : adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }

    cout<<ans+t*((n-2)*(n-1)/2)<<'\n';
}