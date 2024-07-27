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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    sort(all(v));

    int ans = -2e9;
    rep(i,1,n-1){
        ans = max({ans, abs(v[i-1]+v[n-1]-2*v[i]), abs(v[0]+v[n-i]-2*v[n-i-1])});
    }
    cout<<ans<<'\n';


}