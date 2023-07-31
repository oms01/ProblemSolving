#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seg;
ll arr[1'000'001],arr2[1'000'001];

void update(int idx,int st, int en,int i, ll n){
    if(i<st||i>en) return;
    seg[idx]+=n;
    if(st!=en){
        update(idx*2,st,(st+en)/2,i,n);
        update(idx*2+1,(st+en)/2+1,en,i,n);
    }
}
ll cal(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    return cal(idx*2,st,(st+en)/2,l,r) + cal(idx*2+1,(st+en)/2+1,en,l,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back({a,i});
    }
    seg.resize(4*n);
    //init(1,0,n-1);
    
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        arr2[i] = v[i].first;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans+=cal(1,0,n-1,v[i].second+1,n-1);
        update(1,0,n-1,v[i].second,1);
    }

    cout<<ans<<'\n';
    


}
