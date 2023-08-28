#include <bits/stdc++.h>
using namespace std;
int arr[40'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) cin>>arr[i];
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1;i<t;i++){
        if(v.back()<arr[i]) v.push_back(arr[i]);
        else{
            auto it = lower_bound(v.begin(),v.end(),arr[i]);
            *it = arr[i];
        }
    }
    cout<<v.size();
}