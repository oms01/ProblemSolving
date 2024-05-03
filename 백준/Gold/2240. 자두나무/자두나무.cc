#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int t,w;
vector<int> v;
int ans;
int dp[3][1001][31];//위치, 시간, 이동횟수
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t>>w;
    v.resize(t);
    rep(i,0,t) cin>>v[i];

    rep(i,0,t){
        dp[1][i+1][0] = dp[1][i][0] + (v[i]==1);
        rep(j,1,w+1){
            dp[1][i+1][j] = max(dp[1][i][j], dp[2][i][j-1]) + (v[i]==1);
            dp[2][i+1][j] = max(dp[2][i][j], dp[1][i][j-1]) + (v[i]==2);
        }
    }
    rep(i,0,w+1){
        ans = max(ans, max(dp[1][t][w],dp[2][t][w]));
    }
    cout<<ans<<'\n';

}