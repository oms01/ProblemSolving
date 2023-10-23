#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
    ll x,y;
};
int CCW(P a, P b, P c){
    ll ret = (b.x*(c.y-a.y))+(a.x*(b.y-c.y))+(c.x*(a.y-b.y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    P a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    if(CCW(a,b,c)*CCW(a,b,d) <= 0 && CCW(c,d,a)*CCW(c,d,b)<=0){
        cout<<1<<'\n';
    }
    else cout<<0<<'\n';
}
