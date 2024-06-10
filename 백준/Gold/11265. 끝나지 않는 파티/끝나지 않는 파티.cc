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

ll dist[501][501];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i,0,501) fill(dist[i],dist[i]+501,1e9);
    
    int n,m; cin>>n>>m;
    rep(i,0,n) rep(j,0,n){
        int x; cin>>x;
        dist[i][j] = x;
    }

    rep(k,0,n) rep(i,0,n) rep(j,0,n){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        if(dist[s-1][e-1]>x) cout<<"Stay here\n";
        else cout<<"Enjoy other party\n";
    }
}
