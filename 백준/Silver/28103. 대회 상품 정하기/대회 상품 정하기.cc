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
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,x; cin>>n>>m>>x;
    vector<ll> a(m); rep(i,0,m) cin>>a[i];

    x -= a[m-1]*n;
    rep(i,0,m){
        a[i] -= a[m-1];
    }

    vector<ll> ans(m);
    rep(i,0,m-1){
        ll cnt = min(x/a[i],n);
        ans[i] += cnt;
        n -= cnt;
        x -= cnt*a[i];
    }
    ans[m-1] = n;

    for(auto x: ans) cout<<x<<' '; cout<<'\n';
}