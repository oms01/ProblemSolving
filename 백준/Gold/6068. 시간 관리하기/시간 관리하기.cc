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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pii> v(n);
    rep(i,0,n) cin>>v[i].Y>>v[i].X;
    sort(all(v),greater<>());

    int cur = 2e9;
    rep(i,0,n){
        if(cur > v[i].X) cur = v[i].X;
        cur-=v[i].Y;
    }
    cout<<max(-1,cur)<<'\n';
}
