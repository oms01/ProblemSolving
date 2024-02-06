#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
vector<ll> lazy;
ll arr[1'000'001];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(en==st) return seg[idx] = val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(en<l||r<st) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}
void lazy_update(int idx, int st, int en){
    if(!lazy[idx]) return;
    seg[idx] +=(en-st+1)*lazy[idx];
    if(st!=en){
        lazy[idx*2]+= lazy[idx];
        lazy[idx*2+1]+= lazy[idx];
    }
    lazy[idx] = 0;
}
void update_range(int idx, int st, int en, int l, int r, ll val){
    lazy_update(idx,st,en);
    if(en<l||r<st) return;
    if(l<=st&&en<=r){
        seg[idx]+=(en-st+1)*val;
        if(st!=en){
            lazy[idx*2]+=val;
            lazy[idx*2+1]+=val;
        }
        return;
    }
    int mid = (st+en)/2;
    update_range(idx*2,st,mid,l,r,val);
    update_range(idx*2+1,mid+1,en,l,r,val);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}
ll lazy_query(int idx, int st, int en, int l, int r){
    lazy_update(idx,st,en);
    if(en<l||r<st) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return lazy_query(idx*2,st,mid,l,r) + lazy_query(idx*2+1,mid+1,en,l,r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n;
    rep(0,n){
        cin>>arr[i];
    }
    seg.resize(4*n);
    lazy.resize(4*n);
    init(1,0,n-1);
    cin>>m;
    rep(0,m){
        ll a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            update_range(1,0,n-1,b-1,c-1,d);
        }
        else{
            cin>>b;
            cout<<lazy_query(1,0,n-1,b-1,b-1)<<'\n';
        }
    }
}