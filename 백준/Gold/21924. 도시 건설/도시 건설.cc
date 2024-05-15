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

vector<pii> adj[100'001];
bool vis[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    ll ans = 0;
    rep(i,0,m){
        ll st,en,w; cin>>st>>en>>w;
        adj[st].push_back({en,w});
        adj[en].push_back({st,w});
        ans+=w;
    }

    priority_queue<tuple<ll,ll,ll>> pq;
    for(auto nxt:adj[1]){
        pq.push({-nxt.Y, 1, nxt.X});
    }
    vis[1] = 1;
    ll cnt = 1;
    while(!pq.empty() && cnt < n){
        ll st,en,w;
        tie(w,st,en)= pq.top(); pq.pop();
        if(vis[en]) continue;
        vis[en] = 1;
        cnt++;
        ans+=w;
        for(auto nxt: adj[en]){
            if(vis[nxt.X]) continue;
            pq.push({-nxt.Y, en, nxt.X});
        }
    }
    if(cnt<n) cout<<-1<<'\n';
    else cout<<ans<<'\n';


}