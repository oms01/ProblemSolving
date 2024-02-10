#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
ll arr[1'000'001];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    return seg[idx] = init(idx*2,st,(st+en)/2) + init(idx*2+1,(st+en)/2+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(en<i||i<st) return seg[idx];
    if(st==en) return seg[idx] += val;
    return seg[idx] = update(idx*2,st,(st+en)/2,i,val) + update(idx*2+1,(st+en)/2+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return 0;
    if(l<=st&&en<=r) return seg[idx];
    return query(idx*2,st,(st+en)/2,l,r) + query(idx*2+1,(st+en)/2+1,en,l,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    seg.resize(4*n);
    rep(0,n){
        int x; cin>>x;
        v[x-1] = i;
    }
    ll ans = 0;
    rep(0,n){
        ans += query(1,0,n-1,v[i]+1,n-1);
        update(1,0,n-1,v[i],1);
    }
    cout<<ans<<'\n';

}