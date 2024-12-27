#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

ull power(ull x, ull y, ull mod){
    ull ret = 1;
    x%=mod;
    while(y){
        if(y%2) ret = (ret*x)%mod;
        y /= 2;
        x = (x*x)%mod;
    }
    return ret;
}
bool miller(ull n, ull a){
    if(a%n==0) return 1;
    ull k = n-1;
    while(1){
        ull tmp = power(a,k,n);
        if(tmp==n-1) return 1;
        if(k%2) return (tmp==1||tmp==n-1);
        k/=2;
    }
}
bool isPrime(ull n){
    for(ull base:{2,7,61}){
        if(!miller(n,base)) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    int ans = 0;

    rep(i,0,n){
        ull a; cin>>a;
        // a = 2xy + x + y
        // 2a + 1 = (2x+1)(2y+1)
        ans+=isPrime(a*2+1);

    }
    cout<<n-ans<<'\n';

}
