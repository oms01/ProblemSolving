#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string func(string str){
    vector<char> tmp;
    string ret = "";
    for(int i=0;i<str.size();i++) tmp.push_back(str[i]);
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++) ret+=tmp[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> v;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(func(str));
    }

    sort(v.begin(),v.end());

    string ans = "";
    for(int i=0;i<k;i++){
        ans+=v[i];
    }
    string ret = func(ans);
    cout<<ret;
}
