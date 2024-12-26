#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n,m; cin>>n>>m;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    ll cur = 0;
    ll st = 0;
    ll en = 0;

    while(cur+v[en] < m && en < n) cur+=v[en++];
    
    ll ans = cur;
    for(;en<n;en++){
        cur+=v[en];
        while(cur > m) cur-=v[st++];
        ans = max(ans,cur);
    }
    cout<<ans<<'\n';
}
