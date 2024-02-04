#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
ll arr[1'000'001];
int n;
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = 1;
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2, st, mid) + init(idx*2+1, mid+1, en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2, st, mid, l, r) + query(idx*2+1, mid+1, en, l, r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pii> v;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    seg.resize(4*n);
    
    ll ans = 0;
    for(int i=0;i<m;i++){
        ans+=query(1,0,n-1,v[i].Y, n-1);
        update(1,0,n-1,v[i].Y-1,1);
    }
    cout<<ans<<'\n';


}