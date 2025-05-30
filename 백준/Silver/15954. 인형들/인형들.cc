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

const int MX = 500;
ll a[MX+1], sum[MX+1], sum2[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    REP(i,1,n) cin>>a[i];
    REP(i,1,n) sum[i] = sum[i-1] + a[i];
    REP(i,1,n) sum2[i] = sum2[i-1] + (a[i]*a[i]);

    cout<<fixed;
    cout.precision(11);

    ld ans = 2e9;
    REP(i,1,n-m+1){
        REP(j,i+m-1,n){
            ld len = j-i+1;
            ld avg = (sum[j]-sum[i-1])/len;
            ld v = abs(((sum2[j]-sum2[i-1])/len) - (avg*avg));
            ans = min(ans, sqrt(v));
        }
    }
    cout<<ans<<'\n';

}