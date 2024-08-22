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
ll arr[4*MX], seg[4*MX];
ll init(int idx, int st, int en){
    if(st==en) seg[idx] = arr[st];
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}
ll update(int idx, int st, int en, int i, ll val){
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
    int n; cin>>n;

    vector<int> loc(100'001);
    rep(i,0,n){
        int x; cin>>x;
        loc[x] = i;
        update(1,0,MX,i,1);
    }

    vector<int> order(n);
    int tmp = 1;
    for(int i=0;i<n;i+=2){
        order[i] = tmp++;
    }
    tmp = n;
    for(int i=1;i<n;i+=2){
        order[i] = tmp--;
    }

    rep(i,0,n){
        int idx = loc[order[i]];
        if(i%2){
            cout<<query(1,0,MX,idx+1,100'001)<<'\n';
        }
        else{
            cout<<query(1,0,MX,0,idx-1)<<'\n';
        }
        update(1,0,MX,idx,-1);
    }

}