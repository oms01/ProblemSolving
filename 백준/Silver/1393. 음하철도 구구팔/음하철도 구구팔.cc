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

int dist(pii a, pii b){
    return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    pii loc; cin>>loc.X>>loc.Y;
    int x,y,ddx,ddy; cin>>x>>y>>ddx>>ddy;

    int gcd = __gcd(ddx,ddy);
    ddx/=gcd; ddy/=gcd;

    pii ans = {x,y};
    int mn = dist({x,y},loc);
    while(1){
        x+=ddx; y+=ddy;
        int d = dist({x,y},loc);
        if(mn < d) break;
        mn = d;
        ans = {x,y};
    }

    cout<<ans.X<<' '<<ans.Y<<'\n';

}