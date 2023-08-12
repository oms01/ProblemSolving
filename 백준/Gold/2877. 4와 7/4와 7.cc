#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void func(int n){
    while(n>=1){
        v.push_back(n%2);
        n/=2;
    }
    reverse(v.begin(),v.end());
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    func(n+1);
    for(int i=1;i<v.size();i++){
        if(v[i]==0) cout<<4;
        else cout<<7;
    }
    cout<<'\n';
}


