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


int indegree[10'001];
vector<int> adj[10'001], radj[10'001];
vector<vector<int>> scc;
int n,m;
int vis[10'001];
stack<int> s;
int cnt; //scc개수
void dfs(int cur){
    vis[cur]=1;
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
    s.push(cur);
}
void dfs2(int cur, int i){
    vis[cur]=1;
    scc[i].push_back(cur);
    for(auto nxt : radj[cur]){
        if(vis[nxt]) continue;
        dfs2(nxt, i);
    }
}
void kosaraju(){
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
    }
    memset(vis, 0,sizeof(vis));
    while(!s.empty()){
        int cur = s.top(); s.pop();
        if(vis[cur]) continue;
        scc.resize(++cnt);
        dfs2(cur, cnt-1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int st,en; cin>>st>>en;
        adj[st].push_back(en);
        radj[en].push_back(st);
    }
    kosaraju(); //scc 정보 저장

    for(int i=0;i<cnt;i++) sort(all(scc[i]));
    sort(all(scc));
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        for(auto x : scc[i]){
            cout<<x<<' ';
        }
        cout<<"-1\n";
    }

}