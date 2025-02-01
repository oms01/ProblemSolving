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

const int MX = 25;
int dp[MX+1][MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    int a,b; cin>>a>>b;

    int t; cin>>t;
    vector<int> v(t+1,0);
    REP(i,1,t) cin>>v[i];

    REP(i,0,MX) REP(j,0,MX) REP(k,0,MX) dp[i][j][k] = 2e9;
    dp[min(a,b)][max(a,b)][0] = 0;

    REP(I,1,t){
        REP(J,1,n){
            if(v[I]==J) continue;
            //열려있을 문 두개 지정
            int i = min(J,v[I]);
            int j = max(J,v[I]);
            REP(x,1,n) REP(y,x+1,n){
                //이전 상태(x,y)에서 i,j를 열때 필요한 움직임
                dp[i][j][I] = min(dp[i][j][I], dp[x][y][I-1] + min((abs(x-i)+abs(y-j)),(abs(x-j)+abs(y-i))));
            }
        }
    }

    int ans = 2e9;
    REP(i,1,n){
        ans = min(ans, dp[min(i,v[t])][max(i,v[t])][t]);
    }
    cout<<ans<<'\n';
}