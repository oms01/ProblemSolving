#include <bits/stdc++.h>
using namespace std;
int a[100'001],b[100'001];
int arr[100'001];
pair<int,int> path[100'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n; cin>>n;
        a[n] = i;
    }
    for(int i=1;i<=t;i++) cin>>b[i];
    for(int i=1;i<=t;i++) arr[a[b[i]]] = i;


    //LIS 진행
    vector<int> v;
    for(int i=1;i<=t;i++){
        int idx = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        if(idx<v.size()) v[idx] = arr[i];
        else v.push_back(arr[i]);
        path[i] = {idx,arr[i]};
    }
    cout<<v.size()<<'\n';
}