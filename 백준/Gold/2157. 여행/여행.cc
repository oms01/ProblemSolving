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

int dp[301][301];
int cost[301][301];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k; //도시, 나라수, 간선
    rep(i,0,k){
        int s,e,x; cin>>s>>e>>x;
        if(s>e) continue;
        cost[s][e] = max(cost[s][e],x);
    }

    rep(i,0,301) rep(j,0,301) dp[i][j] = -1;

    dp[1][1] = 0;
    rep(i,1,m){
        REP(cur,1,n){
            if(dp[cur][i]==-1) continue;
            REP(nxt,cur+1,n){
                if(cost[cur][nxt]==0) continue;
                dp[nxt][i+1] = max(dp[nxt][i+1],dp[cur][i] + cost[cur][nxt]);
            }

        }
    }

    cout<<*max_element(dp[n],dp[n]+m+1)<<'\n';
    
}
