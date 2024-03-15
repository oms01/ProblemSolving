#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;


vector<int> getFail(string str){
    int len = str.length();
    vector<int> fail(len);
    for(int i=1,j=0;i<len;i++){
        while(j>0 && str[i]!=str[j]) j = fail[j-1];
        if(str[i]==str[j]) fail[i] = ++j;
    }
    return fail;
}

vector<int> kmp(string str, string pattern){
    vector<int> ret;
    vector<int> fail = getFail(pattern);
    for(int i=0,j=0;i<str.size();i++){
        while(j>0&&str[i]!=pattern[j]) j=fail[j-1];
        if(str[i]==pattern[j]){
            if(j==pattern.size()-1){
                ret.push_back(i-pattern.length()+2);
                j = fail[j];
            }
            else j++;
        }
    }
    return ret;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    string pattern="";
    for(int i=0;i<t;i++){
        char c; cin>>c;
        pattern+=c;
    }
    string str="";
    for(int i=0;i<t;i++){
        char c; cin>>c;
        str+=c;
    }
    str+=str;
    str = str.substr(0,str.size()-1);
    vector<int> v = kmp(str,pattern);
    int a = v.size();
    int b = t;
    int gcd = __gcd(a,b);
    cout<<a/gcd<<'/'<<b/gcd<<'\n';

}
