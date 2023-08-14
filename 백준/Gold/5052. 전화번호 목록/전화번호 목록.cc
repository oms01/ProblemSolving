#include <bits/stdc++.h>
using namespace std;

// 	Trie* child[ptr_num];
// 	bool finish, haveChild;
// 	Trie() {
// 		fill(child, child + ptr_num, nullptr);
// 		finish = haveChild = false;
// 	}
// 	~Trie() {
// 		for (int i = 0; i < ptr_num; i++) if (child[i]) delete child[i];
// 	}
// 	void insert(char* key) {
// 		if (*key == '\0') finish = true;
// 		else {
// 			int next = *key - '0';
// 			if (!child[next]) child[next] = new Trie;
// 			haveChild = true;
// 			child[next]->insert(key + 1);
// 		}
// 	}
// 	bool chk() {
// 		if (finish && haveChild) return false;
// 		for (int i = 0; i < ptr_num; i++) {
// 			if (child[i] && !child[i]->chk()) return false;
// 		}
// 		return true;
// 	}
// };
const int len = 10;
struct Trie{
    Trie* child[len];
    bool finish, haveChild;
    Trie(){
        fill(child, child+len, nullptr);
        finish = 0;
        haveChild = 0;
    }
    ~Trie(){
        for(int i=0;i<len;i++) if(child[i]) delete child[i];
    }
    void insert(char* key){
        if(*key == '\0') finish = 1;
        else{
            int nxt = *key - '0';
            if(!child[nxt]) child[nxt] = new Trie;
            haveChild = 1;
            child[nxt]->insert(key+1);
        }
    }
    bool chk(){
        if(finish && haveChild) return 0;
        for(int i=0;i<len;i++){
            if(child[i] && !child[i]->chk()) return 0;
        }
        return 1;
    }
};



int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Trie* root = new Trie;
        for(int i=0;i<n;i++){
            char num[11];
            scanf("%s",num);
            root->insert(num);
        }
        if(root->chk()) cout<<"YES\n";
        else cout<<"NO\n";
        delete root;
    }

}
