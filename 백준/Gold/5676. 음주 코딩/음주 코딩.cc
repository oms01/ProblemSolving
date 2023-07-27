#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> seg;
ll arr[1'000'001];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st]==0 ? 0 :arr[st]/abs(arr[st]);
    return seg[idx] = init(2*idx,st,(st+en)/2) * init(2*idx+1,(st+en)/2+1,en);
}
ll cal(int idx, int st, int en, int l, int r){
    if(l>en || r<st) return 1;
    if(l<=st && en<=r) return seg[idx] = seg[idx]==0 ? 0: seg[idx]/abs(seg[idx]);
    return cal(2*idx,st,(st+en)/2,l,r) * cal(2*idx+1,(st+en)/2+1,en,l,r);
}
ll update(int idx, int st, int en, int i, ll n){
    if(i<st||i>en) return seg[idx];
    if(st==en) return seg[idx]= n==0 ? 0 : n/abs(n);
    return seg[idx] = update(2*idx,st,(st+en)/2,i,n) * update(2*idx+1,(st+en)/2+1,en,i,n);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<n;i++) cin>>arr[i];
        seg.resize(4*n);
        init(1,0,n-1);
        for(int i=0;i<m;i++){
            char a;
            ll b,c;
            cin>>a>>b>>c;
            if(a=='C'){
                update(1,0,n-1,b-1,c);
            }
            else{
                ll ans = cal(1,0,n-1,b-1,c-1);
                if(ans==0) cout<<0;
                else if(ans>0) cout<<'+';
                else cout<<'-';
            }

        }
        cout<<'\n';
    }
}