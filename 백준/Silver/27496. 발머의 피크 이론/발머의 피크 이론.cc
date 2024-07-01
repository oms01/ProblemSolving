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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<ll> v(n+m-1);
    rep(i,m-1,n+m-1) cin>>v[i];

    vector<ll> a(n+m-1);
    ll cur = v[m-1];
    a[m-1] = v[m-1];
    rep(i,m,n+m-1){
        cur += v[i];
        cur -= v[i-m];
        a[i] = cur;
    }

    // rep(i,m-1,n+m-1) cout<<a[i]<<' ';
    // cout<<'\n';
    ll ans = 0;
    cur = 0;
    rep(i,m-1,n+m-1){
        if(129<=a[i] && a[i]<=138) ans++;
    }
    cout<<ans<<'\n';

}