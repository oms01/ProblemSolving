#include<bits/stdc++.h>
using namespace std;
int n;
int arr[501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 2e9;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d = (arr[j]-arr[i])/(j-i);
            int cnt = 0;
            for(int k=0;k<n;k++){
                if(arr[k]!=arr[i]+(k-i)*d) cnt++;
            }
            ans = min(ans,cnt);
        }
    }
    cout<<ans<<'\n';
}