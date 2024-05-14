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
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,1,n+1) rep(j,1,n+1){
        int x; cin>>x;
        if(i==j) continue;
        adj[i].push_back({j,x});
    }

    priority_queue<tuple<int,int,int>> pq;
    vector<bool> vis(n+1,0);
    vis[1]=1;
    for(auto x:adj[1]){
        pq.push({-x.Y,1,x.X});//w,st,en
    }
    ll ans = 0;
    int cnt = 0;
    while(cnt<n-1){
        int st,en,w;
        tie(w,st,en) = pq.top(); pq.pop();
        if(vis[en]) continue;
        vis[en] = 1;
        ans+=-w;
        cnt++;
        for(auto nxt:adj[en]){
            if(vis[nxt.X]) continue;
            pq.push({-nxt.Y, en, nxt.X});
        }
    }
    cout<<ans<<'\n';

}