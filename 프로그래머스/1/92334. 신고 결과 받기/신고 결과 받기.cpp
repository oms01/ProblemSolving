#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> ans(n);
    map<string,int> m;
    for(int i=0;i<id_list.size();i++) m[id_list[i]] = i;
    
    vector<set<string>> v(n); //idx번 회원이 set에게 신고당함
    for(auto x: report){
        vector<string> tmp;
        stringstream ss;
        ss.str(x);
        string a;
        while(ss>>a) tmp.push_back(a);
        
        v[m[tmp[1]]].insert(tmp[0]);
    }
    for(int i=0;i<n;i++){
        if(v[i].size() < k) continue;
        for(auto x:v[i]){
            ans[m[x]]++;
        }
    }
    return ans;
}