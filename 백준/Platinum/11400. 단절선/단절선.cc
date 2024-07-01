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

vector<int> adj[100'005];
set<pii> edge;
int seq, vis[100'005];
int func(int cur, int parent){
    vis[cur] = ++seq;
    int ret = vis[cur];
    for(auto nxt : adj[cur]){
        if(nxt==parent) continue;

        if(!vis[nxt]){
            int tmp = func(nxt, cur);
            if(tmp > vis[cur]){
                edge.insert({min(cur,nxt), max(cur,nxt)});
            }
            ret = min(ret,tmp);
        }
        else{
            ret = min(ret, vis[nxt]);
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    rep(i,1,n+1){
        if(!vis[i]) func(i,1);
    }
    cout<<edge.size()<<'\n';
    for(auto x : edge) cout<<x.X<<' '<<x.Y<<'\n';
}