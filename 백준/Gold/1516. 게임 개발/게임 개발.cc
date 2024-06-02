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

int build[501];
int deg[501];
vector<int> adj[501];
int ans[501];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,1,n+1){
        cin>>build[i];
        int x; 
        while(cin>>x){
            if(x==-1) break;
            deg[i]++;
            adj[x].push_back(i);
        }
    }

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
            if(deg[nxt]) continue;
            q.push(nxt);
        }
    }
    rep(i,1,n+1) cout<<ans[i]<<'\n';
}