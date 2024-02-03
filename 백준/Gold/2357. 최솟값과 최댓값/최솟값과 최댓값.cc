#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1'000'001];
vector<ll> mxt,mnt;
ll initmxt(int idx, int st, int en){
    if(st==en) return mxt[idx] = arr[st];
    int mid = (st+en)/2;
    return mxt[idx] = max(initmxt(2*idx,st,mid),initmxt(2*idx+1,mid+1,en));
}
ll initmnt(int idx, int st, int en){
    if(st==en) return mnt[idx] = arr[st];
    int mid = (st+en)/2;
    return mnt[idx] = min(initmnt(2*idx,st,mid),initmnt(2*idx+1,mid+1,en));
}
ll findmn(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 2e9;
    if(l<=st && en <=r) return mnt[idx];
    int mid = (st+en)/2;
    return min(findmn(2*idx,st,mid,l,r),findmn(2*idx+1,mid+1,en,l,r));
}
ll findmx(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 0;
    if(l<=st && en <=r) return mxt[idx];
    int mid = (st+en)/2;
    return max(findmx(2*idx,st,mid,l,r),findmx(2*idx+1,mid+1,en,l,r));
}
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];

    int h = ceil(log2(n));
    int size = (1<<(h+1));
    mxt.resize(size);
    mnt.resize(size);
    initmxt(1,0,n-1);
    initmnt(1,0,n-1);
    while(m--){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        cout<<findmn(1,0,n-1,a-1,b-1)<<' '<<findmx(1,0,n-1,a-1,b-1)<<'\n';

    }

}