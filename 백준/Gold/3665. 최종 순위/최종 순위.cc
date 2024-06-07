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

string solve(){
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    set<int> adj[501];
    rep(i,0,n) rep(j,i+1,n){
        adj[v[i]].insert(v[j]);
    }
    int m; cin>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        if(adj[e].find(s)!=adj[e].end()) swap(s,e);
        adj[s].erase(e);
        adj[e].insert(s);
    }

    vector<int> radj[501];
    vector<int> deg(501,0);
    rep(i,0,n){
        for(int x:adj[v[i]]){
            radj[x].push_back(v[i]);
            deg[v[i]]++;
        }
    }
    
    queue<int> q;
    rep(i,1,n+1){
        if(adj[i].empty()) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(!q.empty()){
            return "?\n";
        }
        ans.push_back(cur);
        for(int nxt : radj[cur]){
            if(--deg[nxt]) continue;
            q.push(nxt);
        }
    }

    if(ans.size()!=n){
        return "IMPOSSIBLE\n";
    }
    reverse(all(ans));
    rep(i,0,n) cout<<ans[i]<<' ';
    return "\n";

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve();
}