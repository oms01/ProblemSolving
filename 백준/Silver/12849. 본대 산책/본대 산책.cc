#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/


ll dp[100'001][11];
//정과,전산,미래,신양,환경,진리,형남,학생
vector<int> adj[10];
const ll MOD = 1'000'000'007;
void init(){
    adj[0] = {1,2}; adj[1] = {0,2,3}; adj[2] = {0,1,3,4};
    adj[3] = {1,2,4,5}; adj[4] = {2,3,5,6}; adj[5] = {3,4,7};
    adj[6] = {4,7}; adj[7] = {5,6};

    dp[0][0] = 1;
    rep(i,1,10) dp[0][i] = 0;

    rep(i,1,100'001) rep(j,0,8){
        for(auto nxt : adj[j]){
            dp[i][j] += dp[i-1][nxt];
            dp[i][j] %= MOD;
        }
    }   

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int n; cin>>n;
    cout<<dp[n][0]<<'\n';
}
