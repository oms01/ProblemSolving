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

vector<pii> ConvexHull(){
    int idx = 0;
    for(int i=1;i<n;i++){
        if(v[idx].Y > v[i].Y || (v[idx].Y==v[i].Y && v[idx].X > v[i].X)){
            idx = i;
        }
    }
    swap(v[idx],v[0]);
    sort(v.begin()+1,v.end(),cmp);
    // vector<pii> ret = Graham();
    // return ret.size();
    return Graham();

}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }

    vector<pii> hull = ConvexHull();
    
    ll ans = 0;
    for(int i=0;i<hull.size()-1;i++){
        for(int j = i+1;j<hull.size();j++){
            ans = max(ans, dist(hull[i],hull[j]));
        }
    }

    cout<<fixed;
    cout.precision(7);
    cout<<sqrt(ans)<<'\n';
}