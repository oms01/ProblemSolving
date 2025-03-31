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

const int MX = 100'000;
vector<pll> adj[MX+1];
ll dist[MX+1];
void f(int cur,int p){
    for(auto [d,nxt]: adj[cur]){
        if(nxt==p) continue;
        dist[nxt] = dist[cur] + d;
        f(nxt,cur);
    }
}
void solve(){
    ll n,m; cin>>n>>m;
    REP(i,0,n) adj[i].clear();
    fill(dist,dist+MX+1,2e9);
    rep(i,1,n){
        ll a,b,c; cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    dist[1] = 0;
    f(1,-1);
    
    ll ans = *max_element(dist+1,dist+n+1);
    cout<<(ans<m?-1:ans)<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
