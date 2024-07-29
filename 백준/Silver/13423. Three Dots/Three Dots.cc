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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        rep(i,0,n) cin>>v[i];
        set<int> s;
        rep(i,0,n) s.insert(v[i]);
        sort(all(v));

        int ans = 0;
        rep(i,0,n) rep(j,i+1,n){
            ans+=(s.find(2*v[j]-v[i])!=s.end());
        }
        cout<<ans<<'\n';
    }

}
