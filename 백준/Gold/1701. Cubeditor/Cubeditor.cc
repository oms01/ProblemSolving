#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<int> getFail(string str){
    int len = str.length();
    vector<int> fail(len);
    for(int i=1, j=0 ; i<len ; i++){
        while(j>0 && str[i]!=str[j]) j = fail[j-1]; 
        if(str[i]==str[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> kmp(string str, string pattern){
    vector<int> ret;
    vector<int> fail = getFail(pattern);
    for(int i=0,j=0 ; i<str.size() ; i++){
        while(j>0 && str[i]!=pattern[j]) j=fail[j-1];
        if(str[i]==pattern[j]) {
            if(j==pattern.size()-1){ //문자열을 찾았을 때
                ret.push_back(i-pattern.length()+2);
                j = fail[j];
            }
            else j++;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    int ans = 0;    
    rep(i,0,str.length()){
        string tmp = str.substr(i,str.length());
        vector<int> v = getFail(tmp);
        rep(i,0,v.size()) ans = max(ans, v[i]);
    }
    cout<<ans<<'\n';
}