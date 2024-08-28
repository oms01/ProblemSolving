#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
const int MX = 1'000'001;
const ll MOD = 1'000'000'007;
ll seg[4*MX];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = 1;
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx]+=val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val)+update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r)+query(idx*2+1,mid+1,en,l,r);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pii> v(n);
    rep(i,0,n){
        int x,y; cin>>x>>y;
        v[i].X = x+500'000;
        v[i].Y = y+500'000;
    }
    sort(all(v),[&](pii a, pii b){
        if(a.Y==b.Y) return a.X<b.X;
        return a.Y<b.Y;
    });

    for(pii cur : v){
        update(1,0,MX,cur.X,1);
    }

    ll ans = 0;
    ll row = -1;
    rep(i,0,n){
        pii cur = v[i];

        if(row!=cur.Y){
            row = cur.Y;
            for(int j=i ; j<n && row==v[j].Y ; j++){
                update(1,0,MX,v[j].X,-1);
            }
        }

        ll l = query(1,0,MX,0,cur.X-1)%MOD;
        ll r = query(1,0,MX,cur.X+1,MX)%MOD;
        ans += (l*r)%MOD;

    }
    cout<<ans%MOD<<'\n';
}