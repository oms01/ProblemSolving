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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<pii> v(n);
    rep(i,0,n) cin>>v[i].X;
    rep(i,0,n) cin>>v[i].Y;
    sort(all(v),[](pii a, pii b){
        return a.Y<b.Y;
    });

    ll ans = v[0].X;
    priority_queue<int> pq;
    for(int i=1;i<n-1;i+=2){
        pq.push(v[i].X);
        pq.push(v[i+1].X);
        ans+=pq.top(); pq.pop();
    }
    cout<<ans<<'\n';
}


