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
const int MX = 30;
ll dp[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;

    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + (dp[i-2]*2);
    }
    //완벽한 좌우대칭을 제외한 모든 타일은 두번 카운트
    cout<<(n%2 ? dp[n]+dp[(n-1)/2] : dp[n]+dp[n/2]+dp[(n-1)/2]*2)/2<<'\n';
}