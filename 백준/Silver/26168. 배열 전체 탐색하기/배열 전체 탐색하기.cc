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
    sort(all(v));

    rep(i,0,m){
        ll a; cin>>a;
        if(a==1){
            ll x; cin>>x;
            cout<<n-(lower_bound(all(v), x)-v.begin())<<'\n';
        }
        else if(a==2){
            ll x; cin>>x;
            cout<<n-(upper_bound(all(v), x)-v.begin())<<'\n';
        }
        else{
            ll s,e; cin>>s>>e;
            cout<<upper_bound(all(v),e) - lower_bound(all(v),s)<<'\n';
        }
    }
}