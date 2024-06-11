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

int dist[101][101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,1,101) fill(dist[i],dist[i]+101,1e9);

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        dist[s][e] = 1;
        dist[e][s] = 1;
    }

    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    vector<int> p(n,0);
    p[0] = 1; p[1] = 1;
    int ans = 2e9;
    int loc1=-1, loc2=-1;
    do{
        vector<int> loc;
        rep(i,0,n){
            if(!p[i]) continue;
            loc.push_back(i+1);
        }
        int sum = 0;
        rep(i,1,n+1){
            if(p[i-1]) continue;
            sum += min(dist[loc[0]][i], dist[loc[1]][i]);
        }
        if(ans > sum){
            loc1 = loc[0]; loc2 = loc[1];
            ans = sum;
        }
        

    }while(prev_permutation(all(p)));

    cout<<loc1<<' '<<loc2<<' '<<ans*2<<'\n';


}