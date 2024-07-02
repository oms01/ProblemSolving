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

vector<int> adj[100'005];
int seq, vis[100'005];
int ans = 1;
int func(int cur, int parent){
    vis[cur] = ++seq;
    int ret = 2e9;
    bool flag = 0;
    int cnt = 0;
    int retemp = 2e9;
    for(auto nxt : adj[cur]){
        if(nxt==parent) continue;

        if(!vis[nxt]){
            int tmp = func(nxt, cur);
            if(tmp <= vis[cur]) cnt++;
            ret = min(ret,tmp);
        }
        else if(vis[cur] > vis[nxt]){
            retemp = min(retemp, vis[nxt]);
            flag = 1;
        }
    }
    if((flag && ret<=vis[cur])||cnt>1){
        ans = 0;
    }
    return min(ret,retemp);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    rep(i,1,n+1){
        if(!vis[i]) func(i,i);
    }

    if(!ans) cout<<"Not cactus\n";
    else cout<<"Cactus\n";
}