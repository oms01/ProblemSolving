#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
ll arr[1'000'001];
const int MX = 2'000'001;
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
ll find(int idx, int st, int en, ll val){
    if(st==en) return st;
    int mid = (st+en)/2;
    if(val<=seg[idx*2]) return find(idx*2,st,mid,val);
    return find(idx*2+1,mid+1,en,val - seg[2*idx]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    seg.resize(4*MX);
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a==2){
            int tmp = find(1,0,MX-1,b);
            cout<<tmp<<'\n';
            update(1,0,MX-1,tmp,-1);
        }
        else{
            update(1,0,MX-1,b,1);
        }
    }

}