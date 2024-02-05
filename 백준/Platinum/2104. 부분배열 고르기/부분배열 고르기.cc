#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
vector<ll> mnseg;
ll arr[1'000'001];
int n;
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st || en<l) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}

ll func(int a,int b){
    if(a==-1) return b;
    if(b==-1) return a;
    return arr[a] > arr[b] ? b : a;
}
ll mninit(int idx, int st, int en){
    if(st==en) return mnseg[idx] = st;
    int mid = (st+en)/2;
    return mnseg[idx] = func(mninit(idx*2,st,mid) , mninit(idx*2+1,mid+1,en));
}
ll mnquery(int idx, int st, int en, int l, int r){
    if(r<st || en<l) return -1;
    if(l<=st && en<=r) return mnseg[idx];
    int mid = (st+en)/2;
    return func(mnquery(idx*2,st,mid,l,r) , mnquery(idx*2+1,mid+1,en,l,r));
}

ll ans(int st,int en){
    if(st==en) return arr[en]*arr[en];
    int mnidx = mnquery(1,0,n-1,st,en);
    ll w = arr[mnidx] * query(1,0,n-1,st,en);
    if(st<mnidx) w = max(w,ans(st,mnidx-1));
    if(mnidx<en) w = max(w,ans(mnidx+1,en));
    return w;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(4*n);
    mnseg.resize(4*n);
    init(1,0,n-1);
    mninit(1,0,n-1);
    
    cout<<ans(0,n-1)<<'\n';

}