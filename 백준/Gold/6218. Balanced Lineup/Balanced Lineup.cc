#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
vector<ll> mnseg;
ll arr[1'000'001];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = max(init(idx*2, st, mid) , init(idx*2+1, mid+1, en));
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = max(update(idx*2,st,mid,i,val) , update(idx*2+1,mid+1,en,i,val));
}
ll query(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return max(query(idx*2, st, mid, l, r) , query(idx*2+1, mid+1, en, l, r));
}

ll mninit(int idx, int st, int en){
    if(st==en) return mnseg[idx] = arr[st];
    int mid = (st+en)/2;
    return mnseg[idx] = min(mninit(idx*2, st, mid) , mninit(idx*2+1, mid+1, en));
}
ll mnquery(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 2e9;
    if(l<=st && en<=r) return mnseg[idx];
    int mid = (st+en)/2;
    return min(mnquery(idx*2, st, mid, l, r) , mnquery(idx*2+1, mid+1, en, l, r));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    seg.resize(4*n);
    mnseg.resize(4*n);
    init(1,0,n-1);
    mninit(1,0,n-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<abs(query(1,0,n-1,a-1,b-1) - mnquery(1,0,n-1,a-1,b-1))<<'\n';
    }
}