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
    int n,m; cin>>n>>m;
    rep(i,0,m+1){
        int st,en,w; cin>>st>>en>>w;
        adj[st].push_back({w,en});
        adj[en].push_back({w,st});
    }//오르막 0, 내리막 1
    
    priority_queue<pii, vector<pii>, greater<>> pq;
    vis[0] = 1;
    for(auto cur : adj[0]){
        pq.push(cur);
    }
    int cnt = 0;
    int mx = 0;
    while(cnt<n){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        // cout<<cur.X<<' '<<cur.Y<<'\n';
        vis[cur.Y] = 1;
        cnt++;
        mx+=1-cur.X;
        for(auto nxt : adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            // cout<<"<<<";
            // cout<<nxt.X<<' '<<nxt.Y<<'\n';
            pq.push(nxt);
        }
    }
    // cout<<"=========\n";
    memset(vis,0,sizeof(vis));
    priority_queue<pii> pq2;
    vis[0] = 1;
    for(auto cur : adj[0]){
        pq2.push(cur);
    }
    cnt = 0;
    int mn = 0;
    while(cnt<n){
        auto cur = pq2.top(); pq2.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        cnt++;
        mn+=1-cur.X;
        for(auto nxt : adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq2.push(nxt);
        }
    }

    cout<<mx*mx-(mn*mn)<<'\n';


    
}