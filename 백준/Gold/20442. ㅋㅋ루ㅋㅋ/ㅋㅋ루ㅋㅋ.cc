#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
string str;
int ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>str;
    int cnt = 0;
    vector<int> l,r;
    for(int i=0;i<str.length();i++){
        if(str[i]=='K') cnt++;
        else l.push_back(cnt);
    }
    cnt=0;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='K') cnt++;
        else r.push_back(cnt);
    }
    int st = 0, en = r.size()-1;
    reverse(r.begin(),r.end());
    while(st<=en){
        ans = max(ans,(en-st+1)+(2*min(l[st],r[en])));
        if(l[st]<r[en]) st++;
        else en--;
    }
    cout<<ans<<'\n';
}