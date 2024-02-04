#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;//짝
vector<ll> seg2;//홀수 
ll arr[1'000'001];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = (arr[st]%2==0);
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2, st, mid) + init(idx*2+1, mid+1, en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx] = (val%2==0);
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2, st, mid, l, r) + query(idx*2+1, mid+1, en, l, r);
}


ll init2(int idx, int st, int en){
    if(st==en) return seg2[idx] = (arr[st]%2!=0);
    int mid = (st+en)/2;
    return seg2[idx] = init2(idx*2, st, mid) + init2(idx*2+1, mid+1, en);
}
ll update2(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg2[idx];
    if(st==en) return seg2[idx] = (val%2!=0);
    int mid = (st+en)/2;
    return seg2[idx] = update2(idx*2,st,mid,i,val) + update2(idx*2+1,mid+1,en,i,val);
}
ll query2(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 0;
    if(l<=st && en<=r) return seg2[idx];
    int mid = (st+en)/2;
    return query2(idx*2, st, mid, l, r) + query2(idx*2+1, mid+1, en, l, r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(4*n);
    seg2.resize(4*n);
    init(1,0,n-1);
    init2(1,0,n-1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,n-1,b-1,c);
            update2(1,0,n-1,b-1,c);
        }
        else if(a==2){
            cout<<query(1,0,n-1,b-1,c-1)<<'\n';
        }
        else{
            cout<<query2(1,0,n-1,b-1,c-1)<<'\n';
        }
    }
}