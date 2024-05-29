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

vector<int> adj[1'001];
int out[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        out[e]++;
        adj[s].push_back(e);
    }
    queue<int> q;
    vector<int> ans(n+1);
    rep(i,1,n+1){
        if(out[i]) continue;
        ans[i] = 1;
        q.push(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            out[nxt]--;
            if(out[nxt]) continue;
            q.push(nxt);
            ans[nxt] = ans[cur] + 1;
        }
    }

    rep(i,1,n+1) cout<<ans[i]<<' ';
    cout<<'\n';


    
}