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

int dp[10'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int t; cin>>t;
    vector<pii> coins(t);
    for(auto &[a,b]: coins) cin>>a>>b;
    dp[0] = 1;
    for(int i=0;i<t;i++){ //동전 인덱스
        for(int j=n;j>=0;j--){ //금액
            for(int k=1;k<=coins[i].Y;k++){//동전 개수
                int cur = coins[i].X * k;
                if(j-cur >= 0) dp[j] += dp[j-cur];
            }
        }
    }
    cout<<dp[n]<<'\n';


}