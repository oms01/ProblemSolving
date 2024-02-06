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
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(en==st) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(en<l||r<st) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    rep(1,t+1){
        int n,m,k;
        cin>>n>>m>>k;
        seg.clear();
        seg.resize(4*n);
        vector<pii> v;
        rep(0,k){
            int st,en;
            cin>>st>>en;
            v.push_back({en-1,st-1});
        }
        sort(v.begin(),v.end());

        ll ans = 0;
        rep(0,k){
            ans += query(1,0,n-1,v[i].Y+1,n-1);
            update(1,0,n-1,v[i].Y,1);
        }
        cout<<"Test case "<<i<<": "<<ans<<'\n';
    }

}