#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int len = 26;
struct Trie{
    Trie *ch[len];
    Trie *fail;
    bool finish;
    Trie(){
        fill(ch,ch+len,nullptr);
        finish = 0;
    }
    ~Trie(){
        for(int i=0;i<len;i++){
            if(ch[i]) delete ch[i];
        }
    }
    void insert(string str, int idx){
        if(idx==str.size()){
            finish = 1;
            return;
        }
        int nxt = str[idx]-'a';
        if(!ch[nxt]) ch[nxt] = new Trie();
        ch[nxt]->insert(str,idx+1);
    }
};


Trie* initTrie(vector<string> str){
    Trie* root = new Trie();
    for(auto s: str){
        root->insert(s,0);
    }
    
    //failure
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while(!q.empty()){
        auto* cur = q.front(); q.pop();
        for(int i=0;i<len;i++){
            auto nxt = cur->ch[i];
            if(!nxt) continue;

            if(cur==root) nxt->fail = root;
            else{
                auto *dest = cur->fail;
                while(dest!=root && !dest->ch[i]){
                    dest = dest->fail;
                }
                if(dest->ch[i]) dest = dest->ch[i];
                nxt->fail = dest;
            }
            if(nxt->fail->finish) nxt->finish = 1;
            q.push(nxt);
        }
    }
    return root;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];

    Trie* root = initTrie(v);

    int q; cin>>q;
    while(q--){
        string s; cin>>s;

        auto cur = root;
        bool flag = 0;
        for(int i=0;i<s.length();i++){
            auto nxt = s[i]-'a';
            while(cur!=root&&!cur->ch[nxt]){
                cur = cur->fail;
            }
            if(cur->ch[nxt]) cur = cur->ch[nxt];
            if(cur->finish){
                flag = 1;
                break;
            }
        }
        cout<<(flag ? "YES\n":"NO\n");
    }

}