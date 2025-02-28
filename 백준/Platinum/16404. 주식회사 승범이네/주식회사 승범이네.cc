#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<ll> seg,lazy;
void lazy_update(int idx, int st, int en){
    if(!lazy[idx]) return;
    seg[idx] +=(en-st+1)*lazy[idx];
    if(st!=en){
        lazy[idx*2]+= lazy[idx];
        lazy[idx*2+1]+= lazy[idx];
    }
    lazy[idx] = 0;
}
void update_range(int idx, int st, int en, int l, int r, ll val){
    lazy_update(idx,st,en);
    if(en<l||r<st) return;
    if(l<=st&&en<=r){
        seg[idx]+=(en-st+1)*val;
        if(st!=en){
            lazy[idx*2]+=val;
            lazy[idx*2+1]+=val;
        }
        return;
    }
    int mid = (st+en)/2;
    update_range(idx*2,st,mid,l,r,val);
    update_range(idx*2+1,mid+1,en,l,r,val);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}
ll lazy_query(int idx, int st, int en, int l, int r){
    lazy_update(idx,st,en);
    if(en<l||r<st) return 0;
    if(l<=st&&en<=r) return seg[idx];
    int mid = (st+en)/2;
    return lazy_query(idx*2,st,mid,l,r) + lazy_query(idx*2+1,mid+1,en,l,r);
}

vector<int> adj[100'001];
ll dp[100'001];

int t;
ll s[100'001], e[100'001];
void dfs(int cur){
    s[cur]=++t;
    for(auto nxt: adj[cur]){
        dfs(nxt);
    }
    e[cur]=t;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,m; cin>>n>>m;
    REP(i,1,n){
        int x; cin>>x;
        if(x==-1) continue;
        else adj[x].push_back(i);
    }
    
    dfs(1);
    seg.resize(4*n);
    lazy.resize(4*n);

    rep(i,0,m){
        int q; cin>>q;
        if(q==1){
            int a,b; cin>>a>>b;
            update_range(1,1,n,s[a],e[a],b);
        }
        else{
            int a; cin>>a;
            cout<<lazy_query(1,1,n,s[a],s[a])<<'\n';
        }

    }


}