#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1'000'001];
vector<ll> seg;
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(2*idx,st,mid)+init(2*idx+1,mid+1,en);
}
ll sum(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return sum(2*idx, st, mid, l, r) + sum(2*idx+1, mid+1, en, l, r);
}
void update(int idx, int st, int en, int i, ll diff){
    if(i<st || i>en) return;
    seg[idx] += diff;
    if(st!=en){
        int mid = (st+en)/2;
        update(2*idx,st,mid,i,diff);
        update(2*idx+1,mid+1,en,i,diff);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];

    int h = ceil(log2(n));
    int size = (1<<(h+1));
    seg.resize(size);
    init(1,0,n-1);

    for(int i=0;i<m+k;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,n-1,b-1,c-arr[b-1]);
            arr[b-1] = c;
        }
        else{
            cout<<sum(1,0,n-1,b-1,c-1)<<'\n';
        }
    }
}