#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

vector<int> adj[100'001];
int vis[100'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = vis[cur]+1;
            q.push(nxt);
        }
    }

    cout<<vis[n]-2<<'\n';

}