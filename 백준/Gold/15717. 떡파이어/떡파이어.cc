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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const ll MOD = 1e9+7;
ll fast_mul(ll a, ll b){
    ll ret = 1;
    while(b>0){
        if(b&1) ret = a*ret%MOD;
        a = a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    cout<<fast_mul(2,n-1)<<'\n';

}