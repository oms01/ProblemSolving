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
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    string pattern="";
    string str="";
    cin>>str;
    fail(str);
    cout<<str.length()-failure[str.length()-1];
}

