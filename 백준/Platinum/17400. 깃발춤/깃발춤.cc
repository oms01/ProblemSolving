#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

vector<ll> seg;
ll arr[1'000'001];
ll update(int idx, int st, int en, int i, ll val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    seg.resize(4*n);
    rep(i,1,n+1){
        ll a; cin>>a;
        update(1,1,n,i,i%2 ? -a : a);
    }

    rep(i,0,m){
        ll a,b,c; cin>>a>>b>>c;
        if(a==1){
            cout<<abs(query(1,1,n,b,c))<<'\n';
        }
        else{
            update(1,1,n,b,b%2 ? -c : c);
        }
    }
}

