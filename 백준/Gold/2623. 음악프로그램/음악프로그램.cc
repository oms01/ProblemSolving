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

int deg[1001];
vector<int> adj[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int t; cin>>t;
        vector<int> v(t);
        rep(j,0,t) cin>>v[j];
        rep(j,1,t){
            adj[v[j-1]].push_back(v[j]);
            deg[v[j]]++;
        }
    }
    queue<int> q;
    int tmp = 0;
    vector<int> order(n+1,0);
    rep(i,1,n+1){
        if(!deg[i]){
            q.push(i);
            order[i] = ++tmp;
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(--deg[nxt] || order[nxt]) continue;
            order[nxt] = ++tmp;
            q.push(nxt);
        }
    }

    if(tmp!=n){
        cout<<0<<'\n';
        return 0;
    }
    vector<pii> v(n);
    rep(i,0,n) v[i] = {order[i+1], i+1};
    sort(all(v));
    rep(i,0,n) cout<<v[i].Y<<'\n';

}