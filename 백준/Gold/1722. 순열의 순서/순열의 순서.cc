#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[30];
bool arr[30];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a;
    cin>>n;
    fac[0] = 1;
    for(int i=1;i<=20;i++) fac[i] = fac[i-1]*i;

    cin>>a;
    if(a==1){
        ll t;
        cin>>t;

        vector<int> v(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                if(arr[j]) continue;

                if(fac[n-i-1]<t){
                    t-=fac[n-i-1];
                }
                else{
                    v[i]=j;
                    arr[j]=1;
                    break;
                }

            }
        }
        for(int i=0;i<n;i++) cout<<v[i]<<' ';

    }
    else{
        vector<int> v;
        for(int i=0;i<n;i++){
            int t; cin>>t;
            v.push_back(t);
        }

        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<v[i];j++){
                if(!arr[j]){
                    ans+=fac[n-i-1];
                }
            }
            arr[v[i]] = 1;
        }
        cout<<ans+1<<'\n';
    }
}


