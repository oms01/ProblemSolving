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

ll seg[4'000'001];
ll loc[1'000'001];
ll update(int idx, int st, int en, int i, int val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx]+=val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val) + update(idx*2+1,mid+1,en,i,val);
}
ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        memset(loc,0,sizeof(loc));
        memset(seg,0,sizeof(seg));

        for(int i=0;i<n;i++){
            update(1,0,n+m,i,1);
            loc[i+1] = n-i-1;
        }
        int top = n;
        for(int i=0;i<m;i++){
            int x; cin>>x;
            cout<<query(1,0,n+m,loc[x]+1,n+m)<<' ';
            update(1,0,n+m,loc[x],-1);
            loc[x] = top++;
            update(1,0,n+m,loc[x],1);
        }
        cout<<'\n';
    }
    
}