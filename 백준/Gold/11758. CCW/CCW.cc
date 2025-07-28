#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
    int x,y;
};
int CCW(P a, P b, P c){
    ll ret = (b.x*(c.y-a.y))+(a.x*(b.y-c.y))+(c.x*(a.y-b.y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    P a,b,c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    cout<<CCW(a,b,c)<<'\n';
}
