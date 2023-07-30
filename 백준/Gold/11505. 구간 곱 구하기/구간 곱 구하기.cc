#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1'000'000'007

ll arr[1'000'001];
vector<ll> mxt,mnt,seg;
// ll initmxt(int idx, int st, int en){
//     if(st==en) return mxt[idx] = arr[st];
//     int mid = (st+en)/2;
//     return mxt[idx] = max(initmxt(2*idx,st,mid),initmxt(2*idx+1,mid+1,en));
// }
// ll initmnt(int idx, int st, int en){
//     if(st==en) return mnt[idx] = arr[st];
//     int mid = (st+en)/2;
//     return mnt[idx] = min(initmnt(2*idx,st,mid),initmnt(2*idx+1,mid+1,en));
// }
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = (init(2*idx,st,mid) * init(2*idx+1,mid+1,en))%mod;
}
// ll findmn(int idx, int st, int en, int l, int r){
//     if(l>en || r<st) return 2e9;
//     if(l<=st && en <=r) return mnt[idx];
//     int mid = (st+en)/2;
//     return min(findmn(2*idx,st,mid,l,r),findmn(2*idx+1,mid+1,en,l,r));
// }
// ll findmx(int idx, int st, int en, int l, int r){
//     if(l>en || r<st) return 0;
//     if(l<=st && en <=r) return mxt[idx];
//     int mid = (st+en)/2;
//     return max(findmx(2*idx,st,mid,l,r),findmx(2*idx+1,mid+1,en,l,r));
// }
// ll sum(int idx, int st, int en, int l, int r){
//     if(l>en || r<st) return 0;
//     if(l<=st && en<=r) return seg[idx];
//     int mid = (st+en)/2;
//     return sum(2*idx, st, mid, l, r) + sum(2*idx+1, mid+1, en, l, r);
// }
// void update(int idx, int st, int en, int i, ll diff){
//     if(i<st || i>en) return;
//     seg[idx] += diff;
//     if(st!=en){
//         int mid = (st+en)/2;
//         update(2*idx,st,mid,i,diff);
//         update(2*idx+1,mid+1,en,i,diff);
//     }
// }
ll update(int idx, int st, int en, int i, ll n){
    if(i<st||i>en) return seg[idx];
    if(st==en) return seg[idx] = n;
    int mid = (st+en)/2;
    return seg[idx] = update(2*idx,st,mid,i,n)*update(2*idx+1,mid+1,en,i,n) % mod;
 
}
ll times(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 1;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return (times(2*idx,st,mid,l,r) * times(2*idx+1,mid+1,en,l,r))%mod;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];

    int h = ceil(log2(n));
    int size = (1<<(h+1));
    seg.resize(size);
    init(1,0,n-1);
    for(int i=0;i<m+k;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,n-1,b-1,c);
        }
        else{
            cout<<times(1,0,n-1,b-1,c-1)<<'\n';
        }

    }

}