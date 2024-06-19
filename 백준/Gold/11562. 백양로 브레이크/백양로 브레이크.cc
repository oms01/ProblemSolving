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

int dist[301][301];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,301) rep(j,0,301) dist[i][j] = 1e9;
    rep(i,0,301) dist[i][i] = 0;

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        dist[s][e] = 0;
        dist[e][s] = 0;
        if(!x) dist[e][s] = 1;
    }

    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int k; cin>>k;
    rep(i,0,k){
        int s,e; cin>>s>>e;
        cout<<dist[s][e]<<'\n';
    }
}
