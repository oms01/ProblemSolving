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

int dist[501][501];
int rdist[501][501];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,501) rep(j,0,501) dist[i][j] = 1e9;
    rep(i,0,501) rep(j,0,501) rdist[i][j] = 1e9;
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        dist[s][e] = 1;
        rdist[e][s] = 1;
    }

    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) rdist[i][j] = min(rdist[i][j], rdist[i][k] + rdist[k][j]);

    int ans = 0;
    rep(i,1,n+1){
        int cnt = 0;
        rep(j,1,n+1){
            if(i==j) continue;
            cnt += (dist[i][j] < 1e9);
            cnt += (rdist[i][j]< 1e9);
        }
        if(cnt==n-1) ans++;
    }
    cout<<ans<<'\n';
}
