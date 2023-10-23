#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    ll ret = (x1*y2+x2*y3+x3*y1) - (x2*y1+x3*y2+x1*y3);
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<CCW(x1,y1,x2,y2,x3,y3)<<'\n';
}
