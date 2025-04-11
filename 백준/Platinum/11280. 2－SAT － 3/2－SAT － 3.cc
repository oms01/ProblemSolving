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

const int MX = 30'000;
vector<int> adj[MX+1], radj[MX+1];
int scc[MX+1];
int cnt;
int vis[MX+1];
stack<int> s;
int n,m;
void dfs(int cur){
    vis[cur] = 1;
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
    s.push(cur);
}
void rdfs(int cur,int i){
    vis[cur] = 1;
    scc[cur] = i;
    for(auto nxt: radj[cur]){
        if(vis[nxt]) continue;
        rdfs(nxt,i);
    }
}
void kosaraju(){
    REP(i,1,2*n){
        if(vis[i]) continue;
        dfs(i);
    }
    memset(vis,0,sizeof(vis));
    while(!s.empty()){
        int cur = s.top(); s.pop();
        if(vis[cur]) continue;
        rdfs(cur,cnt++);
    }
}

int NOT(int x){
    return x > n ? x-n : x+n;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        if(s<0) s=n-s;
        if(e<0) e=n-e;

        adj[NOT(s)].push_back(e); radj[e].push_back(NOT(s));
        adj[NOT(e)].push_back(s); radj[s].push_back(NOT(e));
    }
    
    kosaraju();

    REP(i,1,n){
        if(scc[i]==scc[i+n]){
            return !(cout<<0<<'\n');
        }
    }
    cout<<1<<'\n';

}

