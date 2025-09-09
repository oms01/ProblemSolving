#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 500'005;
vector<ll> adj[MX+1];
ll vis[MX+1]; //i위치에서의 최대 기력
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,st; cin>>n>>m>>st;
    vector<ll> a(n+1),b(n+1);
    REP(i,1,n) cin>>a[i];
    REP(i,1,n) cin>>b[i];
    while(m--){
        ll s,e; cin>>s>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    
    priority_queue<pll, vector<pll>, greater<>> pq; //요구량, 위치
    pq.push({a[st],st});

    ll ans = 0;
    bool flag = 1;
    while(flag){
        flag = 0;
        while(!pq.empty() && pq.top().X <= ans){
            auto [val, cur] = pq.top(); pq.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            ans += b[cur];
            flag = 1;
            for(auto nxt: adj[cur]){
                if(vis[nxt]) continue;
                pq.push({a[nxt],nxt});
            }
        }
    }
    cout<<ans<<'\n';
}

