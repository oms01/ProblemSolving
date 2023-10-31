#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<double,double> pii;
int n;
int ans;
string str;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>str;

    unordered_map<char,int> m;
    int len = 0;
    while(m.size()<=n && len < str.length()){
        m[str[len]]++;
        len++;
    }

    if(len == str.length()){
        cout<<len<<'\n';
        return 0;
    }

    len--;
    m[str[len]]--;
    if(m[str[len]]==0){
        m.erase(str[len]);
    }

    int st = 0;
    int en = len-1;
    while(1){
        ans = max(ans,abs(en-st+1));
        if(en>=str.length()) break;
        // cout<<st<<' '<<en<<'\n';
        en++;
        m[str[en]]++;
        while(m.size()>n){
            m[str[st]]--;
            if(m[str[st]]==0) m.erase(str[st]);
            st++;
        }
    }
    cout<<ans<<'\n';
}