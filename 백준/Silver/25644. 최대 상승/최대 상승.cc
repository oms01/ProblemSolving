#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    
    int mx = -2e9;
    int mn = 2e9;
    int ans = 0;
    rep(i,0,n){
        int x; cin>>x;
        if(mn > x){
            mn = x;
            mx = -2e9;
        }
        else if(mx < x){
            mx = x;
        }

        if(mn!=2e9 && mx!=-2e9){
            ans = max(ans, mx-mn);
        }
    }

    cout<<ans<<'\n';

}
