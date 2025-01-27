#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

unordered_map<ll,ll> m;
ll n,p,q,x,y;
ll f(ll c){
    if(c<=0) return 1;
    ll a = (m.count(c/p-x) ? m[c/p-x] : f(c/p-x));
    m[c/p-x] = a;
    ll b = (m.count(c/q-y) ? m[c/q-y] : f(c/q-y));
    m[c/q-y] = b;
    return a+b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>p>>q>>x>>y;
    cout<<f(n)<<'\n';
}