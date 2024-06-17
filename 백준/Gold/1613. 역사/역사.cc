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

int dist[401][401];
int rdist[401][401];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i,0,401) rep(j,0,401) dist[i][j] = 1e9;
    rep(i,0,401) dist[i][i] = 0;
    rep(i,0,401) rep(j,0,401) rdist[i][j] = 1e9;
    rep(i,0,401) rdist[i][i] = 0;

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        dist[s][e] = 1;
        rdist[e][s] = 1;
    }
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) rdist[i][j] = min(rdist[i][j], rdist[i][k] + rdist[k][j]);

    int k; cin>>k;
    rep(i,0,k){
        int s,e; cin>>s>>e;
        cout<<(dist[s][e]<1e9 ? -1 : rdist[s][e]<1e9 ? 1 : 0)<<'\n';
    }

}
