#include <bits/stdc++.h>
using namespace std;
vector<int> failure;
void fail(string pattern){
    failure.resize(pattern.length(),0);
    //Failure function
    int j = 0;
    for (int i = 1; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = failure[j - 1];
        if (pattern[i] == pattern[j]) {
            failure[i] = j + 1;
            j++;
        }
    }
}
vector<int> func(string str, string pattern){
    vector<int> ret;
    //KMP function
    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        while (j > 0 && str[i] != pattern[j]) j = failure[j - 1];
        if (str[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                ret.push_back(i-pattern.length()+2);
                j = failure[j];
            }
            else j++;
        }
    }
    return ret;
}
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    string pattern="";
    for(int i=0;i<t;i++){
        char a; cin>>a;
        pattern+=a;
    }
    string str="";
    for(int i=0;i<t;i++){
        char a; cin>>a;
        str+=a;
    }
    str+=str;
    str = str.substr(0,str.size()-1);
    fail(pattern);
    vector<int> v = func(str,pattern);
    int a = v.size();
    int b = t;
    cout<<a/gcd(a,b)<<'/'<<b/gcd(a,b)<<'\n';

}
