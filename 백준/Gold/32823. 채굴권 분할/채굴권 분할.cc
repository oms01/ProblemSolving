#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

typedef pair<long double, long double> pldld;
const long double PI = 3.1415926535;

int ccw(pldld a,pldld b, pldld c){
    ll ret = (b.X*(c.Y-a.Y))+(a.X*(b.Y-c.Y))+(c.X*(a.Y-b.Y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
pldld conv(long double l, long double a){
    pldld ret;
    ret.X = l*sin(a/1800L*PI);
    ret.Y = l*cos(a/1800L*PI);
    return ret;
}
vector<pii> point;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n){
        long double a,b; cin>>a>>b;
        point.push_back({a,b});
    }
    int pl1,pa1; cin>>pa1>>pl1;
    int pl2,pa2; cin>>pa2>>pl2;

    pldld p1 = conv(pl1,pa1);
    pldld p2 = conv(pl2,pa2);

    int cnt = 0;
    rep(i,0,n){
        pldld a = conv(1000,point[i].X);
        pldld b = conv(1000,point[i].Y);
        cnt+=(ccw(a,b,p1)!=ccw(a,b,p2));
    }
    cout<<(cnt%2 ? "NO\n" : "YES\n");

}