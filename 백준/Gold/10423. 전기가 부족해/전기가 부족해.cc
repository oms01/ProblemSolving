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

vector<pii> adj[1001];
int vis[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    vector<int> v(k);
    rep(i,0,k) cin>>v[i];
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        adj[e].push_back({x,s});
    }

    priority_queue<pii,vector<pii>,greater<>> pq;
    for(auto x: v){
        vis[x] = 1;
        for(auto cur : adj[x]) pq.push(cur);
    }
    
    int ans = 0;
    int cnt = 0;
    while(cnt<n-1 && !pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        ans+=cur.X;
        cnt++;
        for(auto nxt : adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }
    cout<<ans<<'\n';

}