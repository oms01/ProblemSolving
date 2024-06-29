#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef tuple<int,int,int> tiii;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll s,e; cin>>s>>e;
    ll ans = 0;
    if(s==1){
        ans++; s++;
    }
    if(s==2 && e!=1){
        ans++; s++;
    }
    cout<<(ans%2 ? 'H':'A')<<'\n';
    ll tmp = 1;
    rep(i,3,e+1){
        if(i%2){
            tmp = (tmp*26)%1'000'000'007;
        }
        if(i>=s){
            ans = (ans+tmp)%1'000'000'007;
        }
    }
    cout<<ans<<'\n';

}