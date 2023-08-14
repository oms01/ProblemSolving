#include <bits/stdc++.h>
using namespace std;

const int len = 10;
struct Trie{
    map<string,Trie*> m;
    void insert(vector<string> &v, int idx){
        if(idx==v.size()) return;
        if(m.find(v[idx])==m.end()){
            Trie* trie = new Trie;
            m.insert({v[idx],trie});
        }
        m[v[idx]]->insert(v,idx+1);
    }
    void chk(int deep){
        for(auto& i : m){
            for(int i=0;i<deep;i++) cout<<"--";
            cout<<i.first<<'\n';
            i.second->chk(deep+1);
        }
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    Trie* root = new Trie;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        vector<string> v(n);
        for(int j=0;j<n;j++){
            cin>>v[j];
        }
        root->insert(v,0);
    }
    root->chk(0);

}
