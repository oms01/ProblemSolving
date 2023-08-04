#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[300'001];
int piz[300'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int d,n;
    cin>>d>>n;
    for(int i=0;i<d;i++){
        cin>>arr[i];
        if(i!=0 && arr[i]>arr[i-1]){
            arr[i]=arr[i-1];
        }
    }
    for(int i=0;i<n;i++){
        cin>>piz[i];
    }
    int cnt = 0;
    for(int i=d-1;i>=0;i--){
        if(piz[cnt] <= arr[i]) cnt++;

        if(cnt==n){
            cout<<i+1<<'\n';
            return 0;
        }
    }
    cout<<0<<'\n';
}

