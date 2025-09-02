#include <bits/stdc++.h>
using namespace std;

const int MX = 5'000'000;
int cnt[MX+1]; //숫자별 등장 횟수
int ans[MX+1];

vector<int> solution(int e, vector<int> starts) {
    vector<int> ret(starts.size());
    
    for(int i=1;i<=MX;i++){
        for(int j=i;j<=MX;j+=i){
            cnt[j]++;
        }
    }
    
    vector<pair<int,int>> v;
    for(int i=0;i<starts.size();i++){
        v.push_back({starts[i], i});
    }
    sort(v.rbegin(),v.rend());
    
    
    int mx = cnt[e];
    int val = e; 
    int cur = e;
    
    for(int i=0;i<v.size();i++){
        while(v[i].first<=cur){
            if(mx <= cnt[cur]){
                val = cur;
                mx = cnt[cur];
            }
            cur--;
        }
        ret[v[i].second] = val;
    }
    
    
    return ret;
}