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
    if(st==en) return seg[idx]=1;
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2,st,mid) + init(idx*2+1,mid+1,en);
}

ll update(int idx, int st, int en, int i, ll val){
    if(i<st||en<i) return seg[idx];
    if(st==en) return seg[idx]+=val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val)+ update(idx*2+1,mid+1,en,i,val);
}

ll query(int idx, int st, int en, int l, int r){
    if(r<st||en<l) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r) + query(idx*2+1,mid+1,en,l,r);
}

ll Find(int idx, int st,int en, int t){
    if(st==en) return st;
    int mid = (st+en)/2;
    if(t<=seg[idx*2]) return Find(idx*2, st, mid, t);
    return Find(idx*2+1, mid+1, en, t-seg[idx*2]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k; //n개, 시작돌, 간격
    while(cin>>n>>k>>m){
        if(n+m+k==0) break;
        init(1,1,n);
        int idx = m;
        int val;
        rep(i,1,n+1){
            val = Find(1,1,n,idx);
            if(i==n) break;
            update(1,1,n,val,-1);
            idx=(idx+k-2)%(n-i)+1;
        }
        cout<<val<<'\n';
    }
}