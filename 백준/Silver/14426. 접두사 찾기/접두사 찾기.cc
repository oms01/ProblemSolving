
#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int t;
struct Trie{
    Trie *ch[26];
    Trie(){
        fill(ch,ch+26,nullptr);
    }
    void insert(string str, int idx){
        if(idx==str.size()) return;
        if(!ch[str[idx]-'a']) ch[str[idx]-'a'] = new Trie();
        ch[str[idx]-'a']->insert(str,idx+1);
    }
    int find(string str, int idx){
        if(idx==str.size()) return 1;
        if(!ch[str[idx]-'a']) return 0;
        return ch[str[idx]-'a']->find(str,idx+1);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    Trie* root = new Trie();
    rep(0,n){
        string str; cin>>str;
        root->insert(str,0);
    }
    int ans = 0;
    rep(0,m){
        string str; cin>>str;
        if(root->find(str,0)) ans++;
    }
    cout<<ans<<'\n';
}