#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
const int MX = 1'000'001;
ll seg[4*MX], arr[4*MX];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx]=arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx]=val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val)+ update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n) cin>>arr[i];
    init(1,0,n-1);

    int m; cin>>m;
    vector<pii> one;
    vector<vector<tiii>> two(100'001);
    int cnt = 0;
    one.push_back({0,0});
    rep(i,0,m){
        int a; cin>>a;
        if(a==1){
            int b,c; cin>>b>>c;
            one.push_back({b-1,c});
        }
        else{
            int b,c,d; cin>>b>>c>>d;
            two[b].push_back({cnt++,c-1,d-1});
        }
    }

    vector<ll> ans(cnt);
    rep(i,0,one.size()){
        if(i!=0) update(1,0,n-1,one[i].X, one[i].Y);
        // rep(j,0,n) cout<<query(1,0,n-1,j,j)<<' '; cout<<'\n';
        for(auto x : two[i]){
            int idx,l,r;
            tie(idx,l,r) = x;
            ans[idx] = query(1,0,n-1,l,r);
            // cout<<ans[idx]<<" ";
        }   
        // cout<<'\n';
    }

    for(auto a : ans){
        cout<<a<<'\n';
    }
    
    
}