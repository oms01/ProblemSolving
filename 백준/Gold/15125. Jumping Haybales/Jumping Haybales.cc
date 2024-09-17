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
struct segtree{
    vector<ll> seg; 
    segtree(int n=2'001){
        seg.resize(4*n);
        fill(all(seg),2e9);
    }
    ll update(int idx, int st, int en, int i, ll val){
        if(i<st||en<i) return seg[idx];
        if(st==en) return seg[idx]=val;
        int mid = (st+en)/2;
        return seg[idx] = min(update(idx*2,st,mid,i,val),update(idx*2+1,mid+1,en,i,val));
    }
    ll query(int idx, int st, int en, int l, int r){
        if(r<st||en<l) return 2e9;
        if(l<=st&&en<=r) return seg[idx];
        int mid = (st+en)/2;
        return min(query(idx*2,st,mid,l,r),query(idx*2+1,mid+1,en,l,r));
    }
};

string board[2'001];
int dp[2'001][2'001];
segtree row[2'001],col[2'001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    rep(i,0,n) cin>>board[i];

    rep(i,0,2'001) fill(dp[i],dp[i]+2'001,2e9);

    dp[0][0] = 0;
    row[0].update(1,0,n-1,0,0);
    col[0].update(1,0,n-1,0,0);
    rep(i,0,n){
        rep(j,0,n){
            if(i==0&&j==0) continue;
            if(board[i][j]=='#') continue;

            //j열의 위쪽 (i-k ~ i)에서 가장 작은 값 찾기
            int val1 = col[j].query(1,0,n-1,max(0LL,i-k),i);
            //i행의 오른쪽 (j-k ~ j)에서 가장 작은 값 찾기
            int val2 = row[i].query(1,0,n-1,max(0LL,j-k),j);
            dp[i][j] = min(val1,val2)+1;

            col[j].update(1,0,n-1,i,dp[i][j]);
            row[i].update(1,0,n-1,j,dp[i][j]);

        }
    }
    cout<< (dp[n-1][n-1]<2e9 ? dp[n-1][n-1] : -1)<<'\n';
}