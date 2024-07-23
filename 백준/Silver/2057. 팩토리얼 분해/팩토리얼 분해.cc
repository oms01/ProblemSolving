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
    vector<ll> f(20);
    f[0] = 1;
    rep(i,1,20){
        f[i] = f[i-1]*i;
    }

    ll n; cin>>n;
    if(n==0) cout<<"NO\n";
    else{
        for(int i=19;i>=0;i--){
            if(n>=f[i]) n-=f[i];
        }
        cout<<(n ? "NO\n" : "YES\n");
    }

}
