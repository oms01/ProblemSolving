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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<int> adj[200'001];
int ans[200'001];
int t;
void dfs(int cur){
    ans[cur] = ++t;
    for(int nxt: adj[cur]){
        if(ans[nxt]) continue;
        dfs(nxt);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,st; cin>>n>>m>>st;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    REP(i,1,n) sort(rall(adj[i]));

    dfs(st);

    REP(i,1,n){
        cout<<ans[i]<<'\n';
    }
}