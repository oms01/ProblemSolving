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

const int MX = 100;
int dp[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k; cin>>n>>m>>k;
    int ans = 0;
    rep(i,0,n){
        string str; cin>>str;
        int cnt = 0;
        rep(j,0,m){
            if(str[j]=='1'){
                cnt = 0;
            }
            else{
                ans+=(++cnt>=k);
            }
        }
    }
    cout<<ans<<'\n';
}