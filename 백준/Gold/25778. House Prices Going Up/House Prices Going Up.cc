#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<ll> seg;
ll arr[1'000'001];
ll n,m,k;
ll init(int idx, int st, int en){
    if(st==en) return seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2, st, mid) + init(idx*2+1, mid+1, en);
}
ll update(int idx, int st, int en, int i, ll n){
    if(st>i || i>en) return seg[idx];
    if(st==en) return seg[idx] += n; 
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2, st, mid, i, n) + update(idx*2+1, mid+1, en, i, n); 
}
ll cal(int idx, int st, int en, int l, int r){
    if(l>en||r<st) return 0;
    if(l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return cal(idx*2, st, mid, l, r) + cal(idx*2+1, mid+1, en, l, r); 
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(4*n);
    init(1,0,n-1);
    cin>>m;
    for(int i=0;i<m;i++){
        char a; int b,c;
        cin>>a>>b>>c;
        if(a=='U'){
            update(1,0,n-1,b-1,c);
        }
        else{
            cout<<cal(1,0,n-1,b-1,c-1)<<'\n';
        }
    }


}