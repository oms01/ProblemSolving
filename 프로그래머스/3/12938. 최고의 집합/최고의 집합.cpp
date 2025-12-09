#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    if(n>s) return {-1};
    vector<int> ans(n,0);
    
    int S = s;
    for(auto& x: ans){
        x = s/n;
        S -= s/n;
    }

    int i = n-1;
    while(S--){
        ans[i]+=1;
        i = (i-1+n)%n;
    }
    
    sort(ans.begin(),ans.end());
    return ans;
}