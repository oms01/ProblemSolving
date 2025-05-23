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

pll frac_sum(pll a, pll b){
    ll X = (a.X*b.Y)+(b.X*a.Y);
    ll Y = (a.Y*b.Y);
    ll gcd = __gcd(X,Y);
    return {X/gcd, Y/gcd};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll n; cin>>n;
    vector<pll> v(n+1);
    rep(i,0,n+1) cin>>v[i].X>>v[i].Y;

    ll s,e; cin>>s>>e;

    pll sum = {0,1};
    REP(i,1,n){
        auto [a,b] = v[i-1];
        auto [x,y] = v[i];

        pll tmp = {b-y,a-x};
        ll l = max(a,s);
        ll r = min(x,e);
        if(l>r) continue;

        tmp.X*=(r-l);
        sum = frac_sum(sum, tmp);
    }

    sum.Y*=e-s;
    sum = frac_sum(sum,{0,1});
    sum = {abs(sum.X),abs(sum.Y)};

    cout<<sum.X;
    if(sum.Y!=1) cout<<'/'<<sum.Y<<'\n';
    
}