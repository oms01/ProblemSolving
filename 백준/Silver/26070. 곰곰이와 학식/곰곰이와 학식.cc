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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

ll ans;
void f(ll&a, ll&b){
    ll tmp = min(a,b);
    ans+=tmp;
    a-=tmp;
    b-=tmp;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b,c; cin>>a>>b>>c; //치, 피, 햄
    ll x,y,z; cin>>x>>y>>z;
    f(a,x); f(b,y); f(c,z);
    ll bef = -1;
    while(bef!=ans){
        bef = ans;
        y += x/3; x%=3;
        f(b,y);
        z += y/3; y%=3;
        f(c,z);
        x += z/3; z%=3;
        f(a,x); 
    }
    cout<<ans<<'\n';
}