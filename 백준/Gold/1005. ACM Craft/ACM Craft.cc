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

int main() {
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> build(n+1,0);
        rep(i,1,n+1) cin>>build[i];
        vector<int> adj[1001];
        vector<int> deg(n+1,0);
        rep(i,0,m){
            int s,e; cin>>s>>e;
            adj[s].push_back(e);
            deg[e]++;
        }
        vector<int> ans(1001,0);

        queue<int> q;
        rep(i,1,n+1){
            if(!deg[i]){
                q.push(i);
                ans[i] = build[i];
            }
        }

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                ans[nxt] = max(ans[nxt], ans[cur] + build[nxt]);
                deg[nxt]--;
                if(deg[nxt]!=0) continue;
                q.push(nxt);
            }
        }
        int a; cin>>a;
        cout<<ans[a]<<'\n';

    }

}