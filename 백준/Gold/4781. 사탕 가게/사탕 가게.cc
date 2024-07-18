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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int dp[20'001]; //i원의 최대가치 dp[i]
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; double tmp;
    while(cin>>n>>tmp){
        if(n==0 && tmp==0.00) break;
        fill(dp,dp+10'001,0);

        int m = (int)(tmp*100.0+0.5);
        rep(i,1,n+1){
            int a; double t;
            cin>>a>>t;
            int b = (int)(t*100.0+0.5);
            rep(j,0,m+1){
                dp[j+b] = max(dp[j+b], dp[j] + a);
            }
        }
        cout<<dp[m]<<'\n';
    }
}