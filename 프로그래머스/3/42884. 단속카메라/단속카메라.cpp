#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    
    sort(routes.begin(),routes.end(), [](auto a, auto b){
        return a[1] < b[1];
    });
    
    int ans = 0, cur = -2e9;
    for(auto c: routes){
        if(cur < c[0]){
            ans++;
            cur = c[1];
        }
    }
    
    return ans;
}