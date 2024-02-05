#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
ll arr[1'000'001];
const int MX = 65537;
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st || en<l) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    seg.resize(4*MX);
    ll mn=2e9, mx=-2e9;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mn = min(mn,arr[i]);
        mx = max(mx,arr[i]);
    }

    ll ans = 0;
    for(int i=0;i<n;i++){
        update(1,0,MX-1,arr[i],1);
        if(i<k-1) continue;

        int st=mn, en=mx;
        while(st<=en){
            int mid = (st+en)/2;
            int cnt = query(1,0,MX-1,0,mid);
            // cout<<0<<'~'<<en<<" : ";
            // cout<<cnt<<'\n';
            if(cnt >= (k+1)/2){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        // cout<<st<<" : "<<arr[st]<<'\n';
        ans+=st;

        update(1,0,MX-1,arr[i-k+1],-1);
    }
    cout<<ans<<'\n';
}