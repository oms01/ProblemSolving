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


vector<pii> v[3];
vector<pii> adj[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n){
        int x,y,z; cin>>x>>y>>z;
        v[0].push_back({x,i});
        v[1].push_back({y,i});
        v[2].push_back({z,i});
    }

    rep(i,0,3) sort(all(v[i]));

    rep(i,0,3){
        rep(j,0,v[i].size()-1){
            pii a = v[i][j];
            pii b = v[i][j+1];
            int dist = abs(a.X-b.X);
            adj[a.Y].push_back({dist, b.Y});
            adj[b.Y].push_back({dist, a.Y});
        }
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    for(auto cur : adj[0]){
        pq.push(cur);
    }
    vector<bool> vis(100'001,0);
    vis[0] = 1;
    int ans = 0;
    int cnt = 1;
    while(cnt<n){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y]=1;
        ans+=cur.X;
        cnt++;
        for(auto nxt: adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }
    cout<<ans<<"\n";

}