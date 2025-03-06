#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int INF = 2e9;
struct node{
    ll lsum, rsum, sum, mxsum;
};
vector<node> seg;
ll arr[1'000'001];
node merge(node a, node b){
    return{
        max(a.lsum, a.sum + b.lsum),
        max(b.rsum, b.sum + a.rsum),
        a.sum + b.sum,
        max({a.mxsum, b.mxsum, a.rsum+b.lsum})
    };
}
node init(int idx, int st, int en){
    if(st==en) return seg[idx] = {arr[st], arr[st], arr[st], arr[st]};
    int mid = (st+en)/2;
    return seg[idx] = merge(init(idx*2,st,mid),init(idx*2+1,mid+1,en));
}
node update(int idx, int st, int en, int i, ll val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx] = {
        seg[idx].lsum+=val,
        seg[idx].rsum+=val,
        seg[idx].sum+=val,
        seg[idx].mxsum+=val
    };
    int mid = (st+en)/2;
    return seg[idx]=merge(update(idx*2,st,mid,i,val),update(idx*2+1, mid+1,en,i,val));
}

node query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return {-INF,-INF,-INF,-INF};
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return merge(query(idx*2,st,mid+1,l,r),query(idx*2+1,mid+1,en,l,r));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    seg.resize(4*3'000);
    int n; cin>>n;
    vector<tiii> v;
    vector<int> tmpx,tmpy;
    rep(i,0,n){
        int a,b,c; cin>>a>>b>>c;
        v.push_back({a,b,c});
        tmpx.push_back(a); tmpy.push_back(b);
    }

    sort(all(tmpx)); tmpx.erase(unique(all(tmpx)),tmpx.end());
    sort(all(tmpy)); tmpy.erase(unique(all(tmpy)),tmpy.end());
    for(auto& [a,b,c]: v){
        a = lower_bound(all(tmpx),a) - tmpx.begin();
        b = lower_bound(all(tmpy),b) - tmpy.begin();
    }

    sort(all(v),[](tiii a, tiii b){
        auto [ax,ay,aw] = a;
        auto [bx,by,bw] = b;
        if(ay==by) return ax<bx;
        return ay<by;
    });

    ll ans = -2e9;

    rep(i,0,n){
        for(auto& a: seg) a = {0,0,0,0};
        int k = 0;
        while(k<v.size() && get<1>(v[k])<i) k++;
        rep(j,i,n){
            while(k<v.size() && i<=get<1>(v[k]) && get<1>(v[k])<=j){
                update(1,0,n-1, get<0>(v[k]), get<2>(v[k]));
                k++;
            }

            ans = max(ans, seg[1].mxsum);
        }

    }
    cout<<ans<<'\n';


}
