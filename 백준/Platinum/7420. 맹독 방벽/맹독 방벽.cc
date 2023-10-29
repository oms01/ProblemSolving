#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define PI 3.1415926525
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> v;
int n,l;
double dist(pii a, pii b){
    return sqrt((a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y));
}
int CCW(pii a, pii b, pii c){
    ll ret = (b.X*(c.Y-a.Y))+(a.X*(b.Y-c.Y))+(c.X*(a.Y-b.Y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
bool cmp(pii a,pii b){
    int chk = CCW(v[0],a,b);
    if(chk) return chk>0 ? 1:0;
    if(dist(v[0],a) < dist(v[0],b)) return 1;
    return 0;
}
vector<pii> Graham(){
    vector<pii> nv;
    for(int i=0;i<n;i++){
        while(2<=nv.size() && CCW(nv[nv.size()-2],nv[nv.size()-1], v[i])<=0){
            nv.pop_back();
        }
        nv.push_back(v[i]);
    }
    return nv;
}
vector<pii> ConvexHull(){
    int idx = 0;
    for(int i=1;i<n;i++){
        if(v[idx].Y > v[i].Y || (v[idx].Y==v[i].Y && v[idx].X > v[i].X)){
            idx = i;
        }
    }
    swap(v[idx],v[0]);
    sort(v.begin()+1,v.end(),cmp);
    vector<pii> ret = Graham();
    return ret;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].X>>v[i].Y;
    }
    vector<pii> v = ConvexHull();

    double ans = 2*PI*l;
    for(int i=0;i<v.size();i++){
        ans+=dist(v[i],v[(i+1)%v.size()]);
    }   

    cout<<round(ans)<<'\n';
}