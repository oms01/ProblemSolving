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
    int st=0, en=n-1;
    while(st<en){
        if(v[st]+v[en] < m){
            st++;
        }
        else if(v[st]+v[en] > m){
            en--;
        }
        else{
            ans++;
            st++; en--;
        }
    }
    cout<<ans<<'\n';
    
}