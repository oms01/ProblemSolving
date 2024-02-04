#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> seg;
ll arr[1'000'001];
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2, st, mid) + init(idx*2+1, mid+1, en);
}
ll update(int idx, int st, int en, int i, ll val){
    if(st>i||i>en) return seg[idx];
    if(st==en) return seg[idx] += val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2, st, mid, l, r) + query(idx*2+1, mid+1, en, l, r);
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
            update(1,0,n-1,b-1,c);
        }
        else{
            cin>>b;
            int st=0, en=n-1;
            while(st<=en){
                int mid = (st+en)/2;
                int cnt = query(1,0,n-1,0,mid);
                if(cnt < b){
                    st = mid + 1;
                }
                else{
                    en = mid - 1;
                }
            }
            cout<<st+1<<'\n';
        }
    }
}