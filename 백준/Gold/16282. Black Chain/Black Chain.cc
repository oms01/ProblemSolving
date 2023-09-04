#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a = (i+1)*((ll)pow(2,i+1)-1)+i;
        if(n<=a){
            cout<<i;
            break;
        }
    }
    return 0;

}
