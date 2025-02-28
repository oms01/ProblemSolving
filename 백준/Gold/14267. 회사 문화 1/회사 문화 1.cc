#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<int> adj[100'001];
ll dp[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    REP(i,1,n){
        int x; cin>>x;
        if(x==-1) continue;
        else adj[x].push_back(i);
    }

    rep(i,0,m){
        int a,b; cin>>a>>b;
        dp[a] += b;
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt: adj[cur]){
            dp[nxt] += dp[cur];
            q.push(nxt);
        }
    }

    REP(i,1,n) cout<<dp[i]<<' '; cout<<'\n';


}