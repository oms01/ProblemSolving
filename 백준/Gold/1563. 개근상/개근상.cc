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

const ll MOD = 1'000'000;
const int MX = 1'000;
ll dp[MX+1][5][5]; //i일까지 지각 j번, 결석 연속 k번

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    /*
    O 출석, L 지각, A 결석
    개근X = L 2번이상 or A 연속 3번 
    */
    
    int n; cin>>n;
   
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){

        //출석
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                dp[i][j][0]+=dp[i-1][j][k];
                dp[i][j][0]%=MOD;
            }
        }

        //지각
        for(int k=0;k<3;k++){
            dp[i][1][0] += dp[i-1][0][k];
            dp[i][1][0]%=MOD;
        }

        //결석
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k+1] += dp[i-1][j][k];
                dp[i][j][k+1]%=MOD;
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            ans += dp[n][i][j];
        }
    }
    cout<<ans%MOD<<'\n';




}