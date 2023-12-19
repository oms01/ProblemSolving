#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n;
vector<int> adj[51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.length();j++){
            if(str[j]=='Y') adj[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        unordered_set<int> s;
        for(auto x:adj[i]){
            s.insert(x);
            for(auto y:adj[x]){
                s.insert(y);
            }
        }
        s.erase(i);
        ans = max(ans, (int)s.size());
    }
    cout<<ans<<'\n';

}