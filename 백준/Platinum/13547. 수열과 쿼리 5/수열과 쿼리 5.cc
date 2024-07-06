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
/*----------------------*/
const int MX = 1'000'001;
int cnt[MX], ans[MX], v[MX];
int cur;
void mi(int s,int e){
    rep(i,s,e+1) cur -= !(--cnt[v[i]]);
}
void pl(int s,int e){
    rep(i,s,e+1) cur += !(cnt[v[i]]++);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,1,n+1) cin>>v[i];

    int q; cin>>q;
    vector<pair<int,pii>> qu;
    rep(i,0,q){
        int s,e; cin>>s>>e;
        qu.push_back({i,{s,e}});
    }
    int sqn = sqrt(n);
    
    sort(all(qu),[&sqn](pair<int,pii> a, pair<int,pii> b){
        if(a.Y.X/sqn!= b.Y.X/sqn) return a.Y.X < b.Y.X;
        return a.Y.Y < b.Y.Y;
    });

    pl(qu[0].Y.X, qu[0].Y.Y);

    ans[qu[0].X] = cur;
    int l = qu[0].Y.X;
    int r = qu[0].Y.Y;

    rep(i,1,q){
        int idx,s,e;
        idx = qu[i].X; tie(s,e) = qu[i].Y;
        if(s<l) pl(s,l-1);
        if(e>r) pl(r+1,e);
        if(s>l) mi(l,s-1);
        if(e<r) mi(e+1,r);

        tie(l,r,ans[idx]) = {s,e,cur};
    }

    rep(i,0,q){
        cout<<ans[i]<<'\n';
    }
    
}