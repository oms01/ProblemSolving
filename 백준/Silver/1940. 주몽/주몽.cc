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
    sort(all(v));

    int ans = 0;
    vector<int> vis(n);
    rep(i,0,n){
        if(vis[i]) continue;
        rep(j,i+1,n){
            if(vis[j]) continue;
            if(v[i]+v[j]==m){
                ans++;
                v[i]=1; v[j]=1;
            }
        }   
    }
    cout<<ans<<'\n';
    
}