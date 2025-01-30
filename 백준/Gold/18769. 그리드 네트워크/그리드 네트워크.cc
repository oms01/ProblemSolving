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

void solve(){

    vector<pll> adj[250'001];
    bool vis[250'001] = {0,};

    int n,m; cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m-1){
            int x; cin>>x;
            adj[j + i*m].push_back({x,j+1 + i*m});
            adj[j+1 + i*m].push_back({x,j + i*m});
        }
    }
    rep(i,0,n-1){
        rep(j,0,m){
            int x; cin>>x;
            adj[j + i*m].push_back({x,j+(i+1)*m});
            adj[j+(i+1)*m].push_back({x,j + i*m});
        }
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    for(auto x: adj[0]) pq.push(x);
    vis[0] = 1;
    ll ans = 0;
    ll cnt = 1;
    while(cnt<n*m){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        ans += cur.X;
        cnt++;
        for(auto nxt: adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }

    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

}