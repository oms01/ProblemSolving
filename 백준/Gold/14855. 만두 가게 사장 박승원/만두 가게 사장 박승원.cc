#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
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

int dp[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    int sc,sd; cin>>sc>>sd;
    for(int I=1;I*sc<=n;I++){
        for(int i=n;i-sc>=0;i--){
            dp[i] = max(dp[i], dp[i-sc]+sd);
        }
    }
    while(m--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        for(int I=1;I*b<=a;I++){
            for(int i=n;i-c>=0;i--){
                dp[i] = max(dp[i], dp[i-c]+d);
            }
        }
    }

    cout<<dp[n]<<'\n';


}