#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MX = 1'000'000'007;
vector<ll> seg;
ll arr[1'000'001];
ll cmp(int a, int b){
    if(a==-1) return b;
    if(b==-1) return a;
    if(arr[a]==arr[b]) return min(a,b);
    return arr[a]>arr[b] ? b : a;
}
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = st;
    int mid = (st+en)/2;
    return seg[idx] = cmp(init(idx*2, st, mid),init(idx*2+1, mid+1, en));
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx];
    int mid = (st+en)/2;
    return seg[idx] = cmp(update(idx*2, st, mid, i, val),update(idx*2+1, mid+1, en, i, val));
}
ll query(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return -1;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return cmp(query(idx*2, st, mid, l, r),query(idx*2+1, mid+1, en, l, r));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(4*n);
    init(1,0,n-1);
    cin>>m;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            arr[b-1] = c;
            update(1,0,n-1,b-1,c);
        }
        else{
            int mn = query(1,0,n-1,b-1,c-1);
            cout<<query(1,0,n-1,b-1,c-1) + 1<<'\n';
        }
    }
}