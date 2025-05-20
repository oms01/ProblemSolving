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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

const int MX = 1e6;
const int MOD = 1e9+7;
ll a[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    a[0] = 1;
    REP(i,1,MX){
        a[i] = a[i-1]*2;
        if(a[i]>=MOD) a[i]-=MOD;
    }

    int n,k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    ll ans = 0;
    for(int i=n-1;i>=0;i--){
        if(v[i]==k) continue;
        ans += a[i];
        if(ans>=MOD) ans-=MOD;
        k = 6 - k - v[i];
    }
    cout<<ans<<'\n';
}