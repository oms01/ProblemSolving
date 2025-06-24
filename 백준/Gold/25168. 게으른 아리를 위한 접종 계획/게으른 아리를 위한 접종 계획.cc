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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 1e4;
vector<pii> adj[MX+1];
int deg[MX+1];
int dist[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        deg[e]++;
    }

    queue<int> q;
    REP(i,1,n){
        if(!deg[i]) q.push(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto [x,nxt]: adj[cur]){
            dist[nxt] = max(dist[nxt], dist[cur]+x+(x>=7));
            if(!--deg[nxt]) q.push(nxt);
        }
    }
    cout<<*max_element(dist+1,dist+n+1)+1;

}