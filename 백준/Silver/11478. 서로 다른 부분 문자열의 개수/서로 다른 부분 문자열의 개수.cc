#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    set<string> s;
    for(int i=1;i<=str.length();i++){
        for(int j=0;j<str.length()-i+1;j++){
            s.insert(str.substr(j,i));
        }
    }
    cout<<s.size()<<'\n';

}

