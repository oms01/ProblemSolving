#include <bits/stdc++.h>
using namespace std;

const int len = 10;
struct Trie{
    map<string,Trie*> m;
    void insert(vector<string> v, int idx){
        if(v.size()==idx) return;
        if(m.find(v[idx])==m.end()){
            Trie* trie = new Trie;
            m.insert({v[idx],trie});
        }
        m[v[idx]]->insert(v,idx+1);
    }
    void chk(int d){
        for(auto& i :m){
            for(int i=0;i<d;i++) cout<<" ";
            cout<<i.first<<'\n';
            i.second->chk(d+1);
        }
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    Trie* root = new Trie;
    while(t--){
        string str;
        cin>>str;
        stringstream ss(str);        
        string a;
        vector<string> v;
        while(getline(ss,a,'\\')){
            v.push_back(a);
        }
        root->insert(v,0);
        cin.ignore();
    }
    root->chk(0);
}
