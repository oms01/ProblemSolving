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

//miller-rabin O(logloglogN)
ull power(__int128 x, __int128 y, __int128 mod){
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
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(ull base:{2,3,5,7,11,13,17,19,23,29,31,37}){
        if(n==base) return 1;
        if(!miller(n,base)) return 0;
    }
    return 1;
}

//pllard_rho O(N^(1/4))
ull abs128(ull x){
    if(x<0) return -x;
    return x;
}
ull gcd(ull a, ull b){
    while(1){
        ull tmp = a%b;
        a = b;
        b = tmp;
        if(b==0) return a;
    }
}
void pollard_rho(ll n, vector<ll>& v){
    if(n==1) return;
    if(n%2==0){
        v.push_back(2);
        pollard_rho(n/2,v);
        return;
    }
    if(isPrime(n)){
        v.push_back(n);
        return;
    }

    __int128 a,b,c;
    __int128 g = n;
    auto f = [&](ll x){
        return (c+power(x,2,n))%n;
    };

    do{
        if(g==n){
            a = b = rand() % (n-2) + 2;
            c = rand() % 20 + 1;
        }
        a = f(a);
        b = f(f(b));
        g = gcd(abs128(a-b),n);
    }while(g==1);
    pollard_rho(g,v);
    pollard_rho(n/g,v);

}

vector<ll> factorize(ll n){
    vector<ll> ret;
    pollard_rho(n,ret);
    sort(all(ret));
    return ret;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n; cin>>n;
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }
    
    vector<ll> ret = factorize(n);
    
    //오일러 피함수
    ull ans = n/ret[0]*(ret[0]-1);
    rep(i,1,ret.size()){
        if(ret[i]!=ret[i-1]) ans = ans/ret[i]*(ret[i]-1);
    }
    cout<<ans<<'\n';



}
