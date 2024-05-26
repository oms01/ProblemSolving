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


vector<int> adj[100'001], radj[100'001];
int n,m;
int vis[100'001];
stack<int> s;
int leader[100'001];
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
    leader[cur] = i;
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
        leader[cur] = cur;
        dfs2(cur, cur);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin>>n){
        if(n==0) break;
        cin>>m;
        for(int i=0;i<100'001;i++){
            adj[i].clear();
            radj[i].clear();
        }
        memset(leader,0,sizeof(leader));
        memset(vis,0,sizeof(vis));

        for(int i=0;i<m;i++){
            int st,en; cin>>st>>en;
            adj[st].push_back(en);
            radj[en].push_back(st);
        }

        kosaraju(); //각 노드별 소속 scc의 leader 노드 저장

        vector<int> outdegree(100'001, 0);
        for(int i=1;i<=n;i++){
            for(auto j:radj[i]){
                if(leader[i]!=leader[j]) outdegree[leader[j]]++;
            }
        }

        int ans = 0;
        set<int> cnt; // outdegree가 0인 scc의 leader노드
        for(int i=1;i<=n;i++){
            if(outdegree[leader[i]]==0){
                ans++;
                cnt.insert(i);
            }
        }

        for(auto x: cnt) cout<<x<<' ';
        cout<<'\n';

    
    }

}