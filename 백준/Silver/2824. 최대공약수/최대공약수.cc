#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1'000'000'000
ll nlist[1000];
ll mlist[1000];
ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    //ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>nlist[i];
    }

    int m; cin>>m;
    for(int i=0;i<m;i++){
        cin>>mlist[i];
    }
    ll ans = 1;
    bool flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll tmp = gcd(nlist[i],mlist[j]);
            ans*=tmp;
            if(ans>=MAX){
                flag = 1;
                ans%=MAX;
            }
            nlist[i]/=tmp;
            mlist[j]/=tmp;
        }
    }
    if(flag){
        printf("%09lld\n",ans);
    }
    else printf("%lld",ans);
}

