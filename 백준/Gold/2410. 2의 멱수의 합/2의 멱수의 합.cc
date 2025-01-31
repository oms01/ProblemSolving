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

ll dp[1'000'001];
const ll MOD = 1'000'000'000;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[1] = 1;
    REP(i,2,1'000'000){
        dp[i] = dp[i-1];
        if(i%2==0) dp[i]+=dp[i/2];
        dp[i]%=MOD;
    }

    int n; cin>>n;
    cout<<dp[n]<<'\n';

}