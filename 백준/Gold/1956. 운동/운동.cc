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
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,1,401) fill(dist[i],dist[i]+401,1e9);

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e,x; cin>>s>>e>>x;
        dist[s][e] = x;
    }

    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    vector<int> p(n,0);
    p[0] = 1; p[1] = 1;
    int ans = 1e9;
    do{
        vector<int> loc;
        rep(i,0,n){
            if(p[i]) loc.push_back(i+1);
        }
        
        ans = min(ans, dist[loc[0]][loc[1]] + dist[loc[1]][loc[0]]);
        
    }while(prev_permutation(all(p)));
    if(ans>=1e9) cout<<-1<<'\n';
    else cout<<ans<<'\n';

}