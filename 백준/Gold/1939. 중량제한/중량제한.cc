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

int parent[300'001];
int Find(int a){
    if(parent[a]==a) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a,int b){
    a = Find(a); b = Find(b);
    parent[a] = b;
}

vector<tuple<int,int,int>> v;
vector<pii> adj[100'001];
int vis[100'001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        v.push_back({c,a,b});
    }
    int st,en; cin>>st>>en;
    //kruskal
    sort(rall(v));
    rep(i,1,n+1) parent[i] = i;
    for(int i=0;i<v.size();i++){
        int a,b,c;
        tie(c,a,b) = v[i];
        if(Find(a)==Find(b)) continue;
        Union(a,b);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    //bfs
    queue<int> q;
    fill(vis,vis+100'001, 2e9);
    q.push(st);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt.X]!=2e9) continue;
            vis[nxt.X] = min(vis[cur], nxt.Y);
            q.push(nxt.X);
        }
    }
    cout<<(vis[en]==2e9 ? 0 : vis[en])<<'\n';
}