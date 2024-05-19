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

vector<pii> adj[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<int> v(n+1); //남초대는 1, 여초대는 2
    rep(i,1,n+1){
        char c; cin>>c;
        v[i] = (c=='M');
    }
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        if(v[s]==v[e]) continue;
        adj[s].push_back({x,e});
        adj[e].push_back({x,s});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    for(auto cur : adj[1]){
        pq.push(cur);
    }
    vector<bool> vis(n+1,0);
    vis[1]=1;
    int ans = 0;
    int cnt = 1;
    while(!pq.empty()&&cnt<n){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        ans+=cur.X;
        cnt++;
        for(auto nxt: adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }
    if(cnt<n) cout<<-1<<'\n';
    else cout<<ans<<'\n';



}