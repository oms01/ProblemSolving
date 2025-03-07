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

const ll INF = 2e17;
const int MX = 100'000;
struct node{ ll lsum, rsum, sum, mxsum; };
vector<node> seg;
ll arr[MX+1];
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

node query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return {-INF,-INF,0,-INF};
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return merge(query(idx*2,st,mid,l,r),query(idx*2+1,mid+1,en,l,r));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    REP(i,1,n) cin>>arr[i];
    
    seg.resize(4*MX);
    init(1,1,n);

    int m; cin>>m;
    while(m--){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        if(y1<x2){
            node l = query(1,1,n,x1,y1);
            node mid = query(1,1,n,y1+1,x2-1);
            node r = query(1,1,n,x2,y2);
            cout<<l.rsum + mid.sum + r.lsum<<'\n';
        }
        else{
            node l = query(1,1,n,x1,x2-1);
            node mid = query(1,1,n,x2,y1);
            node r = query(1,1,n,y1+1,y2);
            cout<<max({mid.mxsum, l.rsum + mid.lsum, mid.rsum + r.lsum, l.rsum + mid.sum + r.lsum})<<'\n';

        }
    }
}
