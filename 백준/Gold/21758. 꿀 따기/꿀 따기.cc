#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100'001];
int sum[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    int ans = 0;
    //벌꿀벌 벌=1,n
    for(int i=2;i<n;i++){ //꿀통
        ans = max(ans,(sum[i]-sum[1]) + (sum[n-1]-sum[i-1]));
    }
    //꿀벌벌 꿀=1
    for(int i=2;i<n;i++){ //벌
        ans = max(ans,(sum[n-1]-arr[i]) + (sum[i-1]));
    }
    //벌벌꿀 꿀=n
    for(int i=2;i<n;i++){ //벌
        ans = max(ans,(sum[n]-sum[1]-arr[i]) + (sum[n]-sum[i]));
    }
    cout<<ans<<'\n';

}