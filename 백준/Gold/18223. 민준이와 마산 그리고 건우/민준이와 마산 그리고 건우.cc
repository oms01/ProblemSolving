#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int dist[100'001];
vector<pii> adj[100'001];

int f(int st, int en){
    fill(dist, dist+100'001, 2e9);
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({dist[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.X != dist[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist[nxt.Y] < dist[cur.Y] + nxt.X) continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
    return dist[en];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,p; cin>>n>>m>>p;
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        adj[s].push_back({x,e});
        adj[e].push_back({x,s});
    }

    cout<<(f(1,n) >= f(1,p) + f(p,n) ? "SAVE HIM\n" : "GOOD BYE\n");
}