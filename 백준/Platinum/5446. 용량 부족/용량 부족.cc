#include <bits/stdc++.h>
using namespace std;
int cnt;
struct Trie{
    map<char,Trie*> m;
    bool finish=0, rm = 0; // rm = 1: 지우면 안됨
    void insert(vector<char> &v, int idx, bool flag){ //flag = 1 : 지우면 안됨
        if(idx==v.size()){
            if(!flag) finish = 1;
            if(flag) rm = true;
            return;
        }
        if(flag) rm = true; 
        if(m.find(v[idx])==m.end()){
            Trie* trie = new Trie;
            m.insert({v[idx],trie});
        }
        m[v[idx]]->insert(v,idx+1,flag);
    }
    void chk(){
        if(!rm){
            cnt++;
            // cout<<"!";
            // cout<<'\n';
            return;
        }
        if(finish) cnt++;
        for(auto& i : m){
            //cout<<i.first<<"("<<i.second->rm<<","<<i.second->finish<<") ";
            i.second->chk();
            //cout<<'\n';
        }
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cnt = 0;
        Trie* root = new Trie;
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++){   
            string str;
            cin>>str;
            vector<char> v;
            for(auto x:str) v.push_back(x);
            root->insert(v,0,0);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            string str;
            cin>>str;
            vector<char> v;
            for(auto x:str) v.push_back(x);
            root->insert(v,0,1);
        }

        root->chk();
        cout<<cnt<<'\n';
    }

}
