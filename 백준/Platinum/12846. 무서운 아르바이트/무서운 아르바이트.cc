#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seg;
ll arr[1'000'001];
int n;
ll func(int a,int b){
    if(a==-1) return b;
    if(b==-1) return a;
    return arr[a] > arr[b] ? b : a;
}
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = st;
    int mid = (st+en)/2;
    return seg[idx] = func(init(idx*2, st, mid) , init(idx*2+1, mid+1, en));
}
ll query(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return -1;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return func(query(idx*2, st, mid, l, r) , query(idx*2+1, mid+1, en, l, r));
}

ll ans(int st, int en){
    int mnidx = query(1,0,n-1,st,en);
    ll w = (en-st+1)*arr[mnidx];

    if(st<=mnidx-1){
        w = max(w, ans(st,mnidx-1));
    }
    if(mnidx+1<=en){
        w = max(w, ans(mnidx+1,en));
    }
    return w;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        seg.resize(4*n);
        init(1,0,n-1);

        cout<<ans(0,n-1)<<'\n';

    // cout<<"@";
}