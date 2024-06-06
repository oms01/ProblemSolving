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
vector<pll> adj[101];
ll deg[101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    rep(i,0,m){
        ll s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        deg[e]+=x;
    }
    vector<ll> cnt(n+1);
    queue<ll> q;
    q.push(n);
    cnt[n] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            cnt[nxt.Y]+=cnt[cur]*nxt.X;
            deg[nxt.Y]-=nxt.X;
            if(deg[nxt.Y]) continue;
            q.push(nxt.Y);
        }
    }
    rep(i,1,n+1){
        if(adj[i].size()) continue;
        cout<<i<<" "<<cnt[i]<<'\n';
    }
}