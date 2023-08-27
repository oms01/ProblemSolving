#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int e,s,m;
    cin>>e>>s>>m;
    int a=0,b=0,c=0;
    int ans = 0;
    while(1){

        if(a==e && b==s && c==m){
            break;
        }
        a = a%15 + 1;
        b = b%28 + 1;
        c = c%19 + 1;

        ans++;
    }
    cout<<ans<<'\n';
}