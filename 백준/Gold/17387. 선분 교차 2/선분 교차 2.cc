#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll,ll> pii;

int CCW(pii a, pii b, pii c){
    ll ret = (b.x*(c.y-a.y))+(a.x*(b.y-c.y))+(c.x*(a.y-b.y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

	
    pii a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;

	if(CCW(a,b,c)*CCW(a,b,d) == 0 && CCW(c,d,a)*CCW(c,d,b) == 0){
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		if(a<=d && c<=b) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
    else if(CCW(a,b,c)*CCW(a,b,d) <= 0 && CCW(c,d,a)*CCW(c,d,b) <= 0){
        cout<<1<<'\n';
    }
    else cout<<0<<'\n';
}
