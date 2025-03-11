#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
set<int> adj[501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[s].insert(e);
        adj[e].insert(s);
    }

    int q; cin>>q;
    while(q--){
        int a,b,c; cin>>a>>b>>c;
        if(a==1){
            adj[b].insert(c);
            adj[c].insert(b);
        }
        else{
            adj[b].erase(c);
            adj[c].erase(b);
        }
        queue<int> q;
        q.push(1);
        vector<int> dist(n+1,2e9);
        dist[1] = 0;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                if(dist[nxt]!=2e9) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        REP(i,1,n) cout<<(dist[i]==2e9 ? -1 : dist[i])<<' '; cout<<'\n';
    }

}