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

vector<pll> v;
int n;
ll dist(pll a, pll b){
    return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
}
int CCW(pll a, pll b, pll c){
    ll ret = (b.X*(c.Y-a.Y))+(a.X*(b.Y-c.Y))+(c.X*(a.Y-b.Y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
bool cmp(pll a,pll b){
    int chk = CCW(v[0],a,b);
    if(chk) return chk>0 ? 1:0;
    if(dist(v[0],a) < dist(v[0],b)) return 1;
    return 0;
}
vector<pll> graham(){
    vector<pll> nv;
    for(int i=0;i<n;i++){
        while(2<=nv.size() && CCW(nv[nv.size()-2],nv[nv.size()-1], v[i])<=0){
            nv.pop_back();
        }
        nv.push_back(v[i]);
    }
    return nv;
}
vector<pll> convexHull(){
    int idx = 0;
    for(int i=1;i<n;i++){
        if(v[idx].Y > v[i].Y || (v[idx].Y==v[i].Y && v[idx].X > v[i].X)){
            idx = i;
        }
    }
    swap(v[idx],v[0]);
    sort(v.begin()+1,v.end(),cmp);
    return graham();
}
void rotatingCalipers(vector<pll>& hull){
    int sz = hull.size();
    ll l=0,r=0;
    for(int i=0;i<sz;i++){
        if(hull[i].X < hull[l].X) l = i;
        if(hull[i].X > hull[r].X) r = i;
    }
    ll ans = dist(hull[l],hull[r]);
    pll p1 = hull[l],p2 = hull[r];

    for(int i=0;i<sz;i++){
        pll prev = {hull[(l+1)%sz].X - hull[l].X, hull[(l+1)%sz].Y - hull[l].Y};
        pll nxt = {hull[r].X - hull[(r+1)%sz].X, hull[r].Y - hull[(r+1)%sz].Y};

        if(CCW({0,0},prev,nxt)>0) l = (l+1)%sz;
        else r = (r+1)%sz;

        ll d = dist(hull[l],hull[r]);
        if(ans <= d){
            ans = d;
            p1 = hull[l];
            p2 = hull[r];
        }
    }
    // cout<<ans<<'\n';

    cout<<p1.X<<' '<<p1.Y<<' '<<p2.X<<' '<<p2.Y<<'\n';

}

void solve(){
    cin>>n;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }

    vector<pll> hull = convexHull();
    rotatingCalipers(hull);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    // int t = 1;
    while(t--){
        v.clear();
        solve();
    }
}