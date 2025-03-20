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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ld sx = 0;
    ld sy = 0;
    ld sxx = 0;
    ld sxy = 0;

    rep(i,0,n){
        ld x,y; cin>>x>>y;
        sx += x;
        sy += y;
        sxx += x*x;
        sxy += x*y;
    }
    if(n*sxx==sx*sx) return !(cout<<"EZPZ\n");

    
    ld a2 = ((n*sxy) - (sx*sy))/(((n*sxx)-(sx*sx)));
    ld b2 = (sy-(a2*sx))/n;

    cout<<fixed;
    cout.precision(15);
    cout<<a2<<' '<<b2<<'\n';


}