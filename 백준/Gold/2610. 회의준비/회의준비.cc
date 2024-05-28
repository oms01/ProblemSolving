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

int vis[102];
vector<vector<int>> group;
int dist[102][102];
int n,m;
void bfs(int st){
    queue<int> q;
    vector<int> ret;
    ret.push_back(st);
    q.push(st);
    vis[st] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        rep(nxt,1,n+1){
            if(vis[nxt] || dist[cur][nxt]==1e9) continue;
            vis[nxt] = 1;
            ret.push_back(nxt);
            q.push(nxt);
        }
    }
    group.push_back(ret);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i,1,n+1) rep(j,1,n+1) dist[i][j] = 1e9;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        dist[s][e] = 1;
        dist[e][s] = 1;
    }

    rep(i,1,n+1){
        if(!vis[i]) bfs(i);
    }
    
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        if(i==j) dist[i][j] = 0;
    }

    vector<int> ans;
    for(auto v: group){
        int n=-1, mn = 2e9;
        for(auto i: v){
            int mx = 0;
            for(auto j: v){
                mx = max(mx, dist[i][j]);
            }
            if(mx < mn){
                mn = mx;
                n = i;
            }
        }
        cout<<'\n';
        ans.push_back(n);
    }
    sort(all(ans));
    cout<<group.size()<<'\n';
    for(auto x: ans) cout<<x<<'\n';
}