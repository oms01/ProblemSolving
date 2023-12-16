#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++) cout<<"12"[i%2]<<' ';
    cout<<"23"[n%2]<<' ';
}