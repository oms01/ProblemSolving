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

vector<pii> adj[51];
int vis[51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int ans = 0;
    rep(i,0,n) rep(j,0,n){
        char c; cin>>c;
        int w = c=='0' ? 0 : c<='Z' ? c-'A'+27 : c-'a'+1;
        ans+=w;
        if(i==j || w==0) continue;
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
    }

    priority_queue<tuple<int,int,int>> pq;
    vis[0] = 1;
    int cnt = 1;
    for(auto nxt: adj[0]){
        pq.push({-nxt.Y, 0, nxt.X});
    }
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