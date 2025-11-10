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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/

const int MX = 5000;
vector<pll> adj[MX+1];
int in[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    rep(i,0,m){
        ll s,e,a; char t;
        cin>>s>>e>>t>>a;
        if(t=='r'){
            a*=-1;
        }
        adj[s].push_back({a,e});
    }

    vector<ll> dist(n+1,2e16);
    
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        in[cur] = 0;
        for(auto [d,nxt]: adj[cur]){
            if(dist[nxt] <= dist[cur]+d) continue;
            dist[nxt] = dist[cur]+d;
            if(!in[nxt]){
                in[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    REP(i,1,n){
        if(dist[i]<0) cout<<i<<'\n';
    }
}