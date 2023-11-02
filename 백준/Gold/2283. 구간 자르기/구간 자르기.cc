#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int arr[1'000'001];
ll n,k;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        for(int j=l+1;j<=r;j++) arr[j]++;
    }
    // for(int i=0;i<=15;i++){
    //     cout<<i<<' '<<arr[i]<<'\n';
    // }
    int st = 0, en = 0;
    int sum = 0;
    while(en<=1'000'001){
        if(sum > k) sum -= arr[++st];
        else if(sum < k) sum += arr[++en];
        else{
            cout<<st<<' '<<en<<'\n';
            return 0;
        }
    }
    cout<<0<<' '<<0<<'\n';

}