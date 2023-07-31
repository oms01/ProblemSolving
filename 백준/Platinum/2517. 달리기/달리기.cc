#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seg;
ll arr[1'000'001];
ll cal(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    return cal(idx*2,st,(st+en)/2,l,r) + cal(idx*2+1,(st+en)/2+1,en,l,r);
}
ll update(int idx, int st, int en, int i, ll n){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx]+=n;
    return seg[idx] = update(2*idx,st,(st+en)/2,i,n) + update(2*idx+1,(st+en)/2+1,en,i,n);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        v[i].first = i+1;
        swap(v[i].first,v[i].second);
    }
    sort(v.begin(),v.end());

    seg.resize(n*4);
    ll ans = 0;
    for(int i=0;i<n;i++){
        cout<<i+1-cal(1,0,n-1,0,v[i].second)<<'\n';
        update(1,0,n-1,v[i].second,1);
    }
}