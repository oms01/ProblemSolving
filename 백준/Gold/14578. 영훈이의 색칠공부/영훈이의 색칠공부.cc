#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
typedef long long ll;
ll d[100'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    d[1] = 0; d[2] = 1;
    ll fac = 2;
    for(int i=3;i<=n;i++){
        fac*=i; fac%=MOD;
        d[i] = (i-1)*(d[i-2] + d[i-1])%MOD;
    }
    cout<<d[n]*fac%MOD<<'\n';
}