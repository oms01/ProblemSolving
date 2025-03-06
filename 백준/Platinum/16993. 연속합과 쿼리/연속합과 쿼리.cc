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
    return merge(query(idx*2,st,mid,l,r),query(idx*2+1,mid+1,en,l,r));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    REP(i,1,n) cin>>arr[i];

    seg.resize(4*100'000);
    init(1,1,n);

    int m; cin>>m;
    while(m--){
        int s,e; cin>>s>>e;
        cout<<query(1,1,n,s,e).mxsum<<'\n';
    }

}
