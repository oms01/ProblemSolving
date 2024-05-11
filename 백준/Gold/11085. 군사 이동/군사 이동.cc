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
/*------------------------------*/

vector<pii> adj[100001];
int vis[100001];
int mn[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int st,en; cin>>st>>en;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    priority_queue<pii> pq;
    mn[st] = 2e9;
    pq.push({mn[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        for(auto nxt : adj[cur.Y]){
            mn[nxt.Y] = max(mn[nxt.Y], min(mn[cur.Y], nxt.X));
            pq.push(nxt);
        }
    }
    cout<<mn[en];

}