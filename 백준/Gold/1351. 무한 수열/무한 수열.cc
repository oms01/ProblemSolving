#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

ll n,p,q;
map<ll,ll> m;
ll f(ll x){
    if(x==0) return 1;
    ll a = (m.count(x/p) ? m[x/p] : f(x/p));
    ll b = (m.count(x/q) ? m[x/q] : f(x/q));
    m[x/p] = a;
    m[x/q] = b;
    return a+b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    m[0] = 1;
    cin>>n>>p>>q;
    cout<<f(n)<<'\n';
}