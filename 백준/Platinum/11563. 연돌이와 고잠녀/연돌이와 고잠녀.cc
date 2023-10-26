#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<double,double> pii;

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
double caldist(pii a, pii b){ //점 사이의 거리 계산
    return sqrt(((a.X-b.X)*(a.X-b.X)) + ((a.Y-b.Y)*(a.Y-b.Y)));
}
double dot(pii a, pii b){ //내적
    return (a.X*b.X) + (a.Y*b.Y);
}
double cross(pii a, pii b){ //외적
    return (a.X*b.Y) - (b.X*a.Y);
}
double theta(pii a, pii b, pii c){
    double x = dot({b.X-a.X, b.Y-a.Y},{c.X-a.X,c.Y-a.Y});
    double y = dot({a.X-b.X, a.Y-b.Y},{c.X-b.X,c.Y-b.Y});
    if(x*y>=0){
        return abs(cross({b.X-a.X, b.Y-a.Y},{c.X-a.X,c.Y-a.Y})/caldist(a,b));
    }
    return 2e9;

}
double cal(pii a, pii b, pii c, pii d){
    double dist = 2e9;
    dist = min(dist,caldist(a,c)); //점과 점 사이의 거리
    dist = min(dist,caldist(a,d));
    dist = min(dist,caldist(b,c));
    dist = min(dist,caldist(b,d));

    dist = min(dist,theta(a,b,c));
    dist = min(dist,theta(a,b,d));
    dist = min(dist,theta(c,d,a));
    dist = min(dist,theta(c,d,b));
    return dist;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; //신촌, 안암
    cin>>n>>m;
    vector<pair<pii,pii>> A; //신촌
    vector<pair<pii,pii>> B; //안암
    for(int i=0;i<n;i++){
        pii x,y;
        cin>>x.X>>x.Y>>y.X>>y.Y;
        A.push_back({x,y});
    }
    for(int i=0;i<m;i++){
        pii x,y;
        cin>>x.X>>x.Y>>y.X>>y.Y;
        B.push_back({x,y});
    }
    double ans = 2e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pii a,b,c,d;
            tie(a,b) = A[i]; tie(c,d) = B[j];

            ans = min(ans,cal(a,b,c,d));

        }
    }
    cout<<fixed;
    cout.precision(16);
    cout<<ans<<'\n';


}
