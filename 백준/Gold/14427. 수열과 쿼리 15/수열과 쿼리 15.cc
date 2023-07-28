#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> seg;
ll arr[1'000'001];
ll func(int a,int b){
    if(arr[a]==arr[b]) return min(a,b);
    return arr[a]>arr[b] ? b:a;
}
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = st;
    return seg[idx] = func(init(2*idx,st,(st+en)/2) , init(2*idx+1,(st+en)/2+1,en));
}
ll cal(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 2e9;
    if(l<=st && en<=r) return seg[idx];
    return func(cal(2*idx,st,(st+en)/2,l,r) , cal(2*idx+1,(st+en)/2+1,en,l,r));
}
ll update(int idx, int st, int en, int i, ll n){
    if(i<st||i>en) return seg[idx];
    if(st==en) return seg[idx];
    return seg[idx] = func(update(2*idx,st,(st+en)/2,i,n) , update(2*idx+1,(st+en)/2+1,en,i,n));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(4*n);
    init(1,0,n-1);

    cin>>m;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            arr[b-1]=c;
            update(1,0,n-1,b-1,c);
        }
        else{
            cout<<seg[1]+1<<'\n';
        }
    }
    cout<<'\n';
}