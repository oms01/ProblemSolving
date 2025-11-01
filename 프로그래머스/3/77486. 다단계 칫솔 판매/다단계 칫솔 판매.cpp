#include <bits/stdc++.h>

using namespace std;

const int MX = 10'000;
map<string,int> idx;
int parent[MX+1];
vector<int> ans;

void f(int idx, int val){
    if(idx==-1 || val==0) return;
    int cost = val/10;
    ans[idx] += val - cost;
    f(parent[idx], cost);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    ans.resize(enroll.size());
    for(int i=0;i<enroll.size();i++){
        idx[enroll[i]] = idx.size();
    }
    idx["-"] = -1;
    
    for(int i=0;i<enroll.size();i++){
        parent[idx[enroll[i]]] = idx[referral[i]];
    }
    
    for(int i=0;i<seller.size();i++){
        f(idx[seller[i]], amount[i]*100);
    }

    return ans;
}