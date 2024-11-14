#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 501;

int n,m,k;
int d[MX];
vector<pii> adj[MX];
bool bellman(int st){
    d[st] = 0;
    rep(i,0,n) rep(cur,1,n+1){
        rep(k,0,adj[cur].size()){
            int nxt = adj[cur][k].Y;
            int cost = adj[cur][k].X;
            if(d[nxt] > d[cur] + cost){
                d[nxt] = d[cur] + cost;
                if(i==n-1) return 1;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        rep(i,0,MX) adj[i].clear();
        fill(d,d+MX,2e9);
        cin>>n>>m>>k;
        rep(i,0,m){
            int s,e,c; cin>>s>>e>>c;
            adj[s].push_back({c,e});
            adj[e].push_back({c,s});
        }
        rep(i,0,k){
            int s,e,c; cin>>s>>e>>c;
            adj[s].push_back({-c,e});
        }
        cout<<(bellman(1) ? "YES\n" : "NO\n");
    }
}
