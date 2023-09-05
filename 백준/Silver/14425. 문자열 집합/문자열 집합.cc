#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;    
    cin>>n>>m;
    map<string,bool> a;
    while(n--){
        string str;
        cin>>str;
        a[str] = 1;
    }
    int ans = 0;
    while(m--){
        string str;
        cin>>str;
        ans+=a[str];
    }
    cout<<ans<<'\n';

}