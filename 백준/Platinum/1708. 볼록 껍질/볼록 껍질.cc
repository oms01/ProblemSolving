#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> v;
int n;
ll dist(pii a, pii b){
    return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
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
int ConvexHull(){
    int idx = 0;
    for(int i=1;i<n;i++){
        if(v[idx].Y > v[i].Y || (v[idx].Y==v[i].Y && v[idx].X > v[i].X)){
            idx = i;
        }
    }
    swap(v[idx],v[0]);
    sort(v.begin()+1,v.end(),cmp);
    vector<pii> ret = Graham();
    // for(auto x:ret){
    //     cout<<x.X<<' '<<x.Y<<'\n';
    // }
    return ret.size();

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].X>>v[i].Y;
    }
    cout<<ConvexHull();
}