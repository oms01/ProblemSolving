#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> ans;
    stack<int> s;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        while(!s.empty() && s.top() <= v[i]) s.pop();
        
        if(s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());
        
        s.push(v[i]);
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}