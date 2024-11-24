#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

const ll INF = 2e14;
vector<pll> adj[10'001];
ll height[10'001];
ll n,m,d,e;


vector<ll> dijkstra(ll st, ll lim){
    vector<ll> d(10'001,INF);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y]!=cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y]<=d[cur.Y]+(nxt.X>lim)) continue;
            d[nxt.Y] = d[cur.Y] + (nxt.X>lim);
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    rep(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    int st = 0, en = 1'000'001;
    int ans = -1;
    while(st<=en){
        int mid = (st+en)/2;
        if(dijkstra(1,mid)[n] <= k){
            ans = mid;
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    cout<<ans<<'\n';
}

