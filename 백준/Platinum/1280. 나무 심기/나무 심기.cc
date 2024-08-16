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
const int MX = 200'000;
const int MOD = 1'000'000'007;

struct segtree{
    vector<ll> seg;
    segtree(int n){
        seg.resize(4*n);
    }
    ll update(int idx, int st, int en, int i, ll val){
        if(i<st||en<i) return seg[idx];
        if(st==en) return seg[idx]+=val;
        int mid = (st+en)/2;
        return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
    }
    ll query(int idx, int st, int en, int l, int r){
        if(r<st||en<l) return 0;
        if(l<=st&&en<=r) return seg[idx];
        int mid = (st+en)/2;
        return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    segtree cnt(MX+1), sum(MX+1);

    ll ans = 1;
    rep(i,0,n){
        ll x; cin>>x;
        ll front_cnt = cnt.query(1,0,MX+1,0,x-1);
        ll front_sum = sum.query(1,0,MX+1,0,x-1);
        ll back_cnt = cnt.query(1,0,MX+1,x+1,MX+1);
        ll back_sum = sum.query(1,0,MX+1,x+1,MX+1);

        ll val = ((front_cnt*x) - front_sum) + (back_sum - (back_cnt*x));
        if(i!=0) ans*=val%MOD;
        ans%=MOD;

        cnt.update(1,0,MX+1,x,1);
        sum.update(1,0,MX+1,x,x);
        
    }
    cout<<ans<<'\n';
    
}