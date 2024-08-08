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
int a,b,c,d;
int f(int x){
    return max(a*(x-b)*(x-b)+c, d);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c>>d;
    int n; cin>>n;
    int ans=0;
    rep(i,0,n){
        int x,y; cin>>x>>y;
        ans+=(f(y)==x&&b<=y);
    }
    cout<<ans<<'\n';
}