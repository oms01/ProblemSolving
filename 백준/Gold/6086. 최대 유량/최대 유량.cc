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
const int MX = 60;
int c[MX][MX], level[MX], work[MX];
vector<int> g[MX];
int ctoi(char c){
    if(c<='Z') return c-'A';
    return c-'a'+26;
}
int st = ctoi('A');
int en = ctoi('Z');
bool bfs(){
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(st);
    level[st] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int nxt : g[cur]){
            if(level[nxt]!=-1 || c[cur][nxt]<=0) continue;
            level[nxt] = level[cur] + 1;
            q.push(nxt);
        }
    }
    return (level[en]!=-1);
}
int dfs(int cur, int ret){
    if(cur==en) return ret;
    for(int i=work[cur]; i<g[cur].size();i++){
        int nxt = g[cur][i];
        if(level[nxt]!=level[cur]+1 || c[cur][nxt]<=0) continue;
        int tmp = dfs(nxt, min(ret, c[cur][nxt]));
        if(tmp > 0){
            c[cur][nxt] -= tmp;
            c[nxt][cur] += tmp;
            return tmp;
        }
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    rep(i,0,n){
        char s,e; int x; 
        cin>>s>>e>>x;
        int u = ctoi(s); int v = ctoi(e);
        c[u][v]+=x; c[v][u]+=x;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    while(bfs()){
        memset(work, 0, sizeof(work));
        int flow;
        while(flow = dfs(st,2e9)) ans +=flow;
    }
    cout<<ans<<'\n';
    
}