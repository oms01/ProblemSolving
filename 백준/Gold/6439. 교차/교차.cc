#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;

int CCW(pii a, pii b, pii c){
    ll ret = (b.X*(c.Y-a.Y))+(a.X*(b.Y-c.Y))+(c.X*(a.Y-b.Y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
bool chk(pii a, pii b, pii c, pii d){ //교차하면 1
    if(CCW(a,b,c)*CCW(a,b,d) == 0 && CCW(c,d,a)*CCW(c,d,b) == 0){
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		if(a<=d && c<=b) return 1;
		else return 0;
	}
    if(CCW(a,b,c)*CCW(a,b,d) <= 0 && CCW(c,d,a)*CCW(c,d,b)<=0){
        return 1;
    } 
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        pii x,y;
        pii p1,p2;
        cin>>x.X>>x.Y>>y.X>>y.Y;
        cin>>p1.X>>p1.Y>>p2.X>>p2.Y;


        pii a,b,c,d;
        a = p1;
        b = p2;
        c = {p1.X,p2.Y};
        d = {p2.X,p1.Y};

        vector<pii> v(4,{0,0});
        v[0] = a, v[1] = b, v[2] = c, v[3] = d;
        sort(v.begin(),v.end());
        pii mn = v[0];
        pii mx = v[3];


        //점 중 적어도 하나가 내부
        if((mn.X<=x.X && x.X<=mx.X && mn.Y<=x.Y && x.Y<=mx.Y)||(mn.X<=y.X && y.X<=mx.X && mn.Y<=y.Y && y.Y<=mx.Y)){
            cout<<"T"<<'\n';
            continue;
        }

        //둘다 외부
        if(chk(x,y,a,c)||chk(x,y,a,d)||chk(x,y,b,d)||chk(x,y,b,c)){
            cout<<"T"<<'\n';
        }
        else cout<<"F"<<'\n';

    }
}
