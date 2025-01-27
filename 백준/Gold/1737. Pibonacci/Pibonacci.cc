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

map<ld,ll> m;
const ld PI = 3.14'1592'6535'8979'3238;
const ll MOD = 1'000'000'000'000'000'000;
ll f(ld x){
    if(0<=x && x<=PI) return 1;
    ll a = (m.count(x-1) ? m[x-1] : f(x-1));
    ll b = (m.count(x-PI) ? m[x-PI] : f(x-PI));
    m[x-1] = a%MOD;
    m[x-PI] = b%MOD;
    m[x] = (a+b)%MOD;
    return m[x];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ld x; cin>>x;
    cout<<f(x)<<'\n';
}