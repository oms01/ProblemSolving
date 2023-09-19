#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,q;
    cin>>n>>k>>q;
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        if(k==1){
            cout<<abs(a-b)<<'\n';
            continue;
        }
        ll ans=0;
        while(a!=b){
            while(a>b){
                ans++;
                a = (a+k-2)/k;
            }
            while(a<b){
                ans++;
                b = (b+k-2)/k;
            }
        }
        cout<<ans<<'\n';
    }

}