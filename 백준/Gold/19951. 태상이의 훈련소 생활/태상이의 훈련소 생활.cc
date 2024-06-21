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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    vector<int> d(n+1);
    rep(i,0,m){
        int st,en,k; cin>>st>>en>>k;
        d[st-1]+=k; d[en]+=-k;
    }
    rep(i,1,n) d[i] += d[i-1];

    rep(i,0,n) cout<<v[i]+d[i]<<' ';
    cout<<'\n';
}
