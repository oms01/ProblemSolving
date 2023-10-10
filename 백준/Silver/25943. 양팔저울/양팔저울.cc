#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
int a[10'001];
int w[] = {1,2,5,10,20,50,100};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    l = a[0]; r = a[1];
    for(int i=2;i<n;i++){
        if(l==r) l += a[i];
        else (l<r ? l : r) += a[i];
    }
    int d = abs(l-r);
    for(int i=6;i>=0;i--){
        ans += d/w[i];
        d%=w[i];
    }
    cout<<ans<<'\n';
    return 0;
}