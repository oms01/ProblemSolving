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
    vector<ll> v(m);
    ll cur = 0;
    ll ans = 0;
    rep(i,0,n) rep(j,0,m){
        int x; cin>>x;
        v[j]+=x;
    }

    int l; cin>>l;
    rep(i,0,m){
        cur += v[i];
        if(i>=l) cur-=v[i-l];
        ans = max(ans,cur);
    }
    cout<<ans<<'\n';
}