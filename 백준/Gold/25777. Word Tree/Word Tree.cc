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
vector<pii> adj[1'001];
int vis[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];

    rep(i,0,n) rep(j,i+1,n){
        int dist = 0;
        rep(k,0,m){
            dist += abs(v[i][k]-v[j][k]);
        }
        adj[i].push_back({dist,j});
        adj[j].push_back({dist,i});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    vis[0] = 1;
    for(auto cur : adj[0]){
        pq.push(cur);
    }
    int mx=-1;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        mx = max(mx,cur.X);
        for(auto nxt : adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }
    cout<<mx<<'\n';



}