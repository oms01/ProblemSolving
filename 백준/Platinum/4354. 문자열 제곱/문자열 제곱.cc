#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

vector<int> getFail(string str){
    int len = str.length();
    vector<int> fail(len);
    for(int i=1,j=0;i<len;i++){
        while(j>0 && str[i]!=str[j]) j = fail[j-1];
        if(str[i]==str[j]) fail[i] = ++j;
    }
    return fail;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string str;
    while(cin>>str){
        if(str==".") break;
        vector<int> v = getFail(str);
        int tmp = str.length() - v[str.length()-1];
        if(str.length()%tmp) cout<<1<<'\n';
        else cout<<str.length()/tmp<<'\n';
        
    }
}
