#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

pll add(pll a, pll b){
    ll x = a.X*b.X;
    ll y = (b.X*a.Y) + (a.X*b.Y);
    ll gcd = __gcd(x,y);
    return {x/gcd,y/gcd};
}

pll subtract(pll a, pll b){
    ll x = a.X*b.X;
    ll y = (b.X*a.Y) - (a.X*b.Y);
    ll gcd = __gcd(x,y);
    return {x/gcd,y/gcd};
}


void solve(){
    ll n,m; cin>>n>>m;
    vector<pll> ans(n,{1,0});
    rep(i,0,m){
        ll sum; cin>>sum;
        rep(j,0,n){
            ll x; cin>>x;
            ans[j] = add(ans[j], {sum,x});
        }
    }

    sort(all(ans),[](pll a, pll b){
        return a.Y*b.X < a.X*b.Y;
    });


    pll a = subtract(ans.back(),ans[0]);

    if(a.X==1){
        cout<<a.Y<<'\n';
    }
    else{
        cout<<a.Y<<'/'<<a.X<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}


