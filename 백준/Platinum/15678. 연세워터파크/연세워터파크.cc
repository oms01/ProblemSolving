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
ll seg[4*MX], arr[4*MX];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx]=arr[st];
    int mid = (st+en)/2;
    return seg[idx] = max(init(idx*2,st,mid), init(idx*2+1,mid+1,en));
}
ll update(int idx, int st, int en, int i, ll val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx]+=val;
    int mid = (st+en)/2;
    return seg[idx] = max(update(idx*2,st,mid,i,val), update(idx*2+1,mid+1,en,i,val));
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return -2e9;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return max(query(idx*2,st,mid,l,r),query(idx*2+1,mid+1,en,l,r));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;

    rep(i,0,n){
        int x; cin>>x;
        ll tmp = max(0LL, query(1,0,n-1,max(0LL,i-m), max(0LL, i-1)))+x;
        update(1,0,n-1,i,tmp);
    }
    cout<<query(1,0,n-1,0,n-1)<<'\n';
    
}