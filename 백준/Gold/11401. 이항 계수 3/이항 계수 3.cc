#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;
ll pow(ll n, ll k){ //모듈러 역원을 이용한 이항계수(조합)
    ll ret = 1;
    while(k){
        if(k%2) ret = (ret*n)%mod;
        n = (n*n)%mod;
        k/=2;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    ll a = 1, b = 1;
    for(int i=n;i>=n-k+1;i--) a = (a*i)%mod;
    for(int i=2;i<=k;i++) b = (b*i)%mod;
    cout<<(a*pow(b,mod-2))%mod;
}