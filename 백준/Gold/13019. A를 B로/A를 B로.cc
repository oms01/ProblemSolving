#include<bits/stdc++.h>
using namespace std;
string a,b;
int cnt;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    int j=b.length()-1;
    for(int i=a.length()-1;i>=0;i--){
        if(a[i]==b[j]) j--;
        else cnt++;
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a==b) cout<<cnt<<'\n';
    else cout<<-1<<'\n';
}