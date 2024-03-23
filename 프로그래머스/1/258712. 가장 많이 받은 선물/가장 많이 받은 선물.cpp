#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string,int> m;
    vector<vector<int>> v(friends.size(),vector<int>(friends.size()));
    for(auto cur : friends) m[cur] = m.size();
    map<int,int> point;
    for(auto cur : gifts){
        string a,b;
        stringstream ss(cur);
        ss>>a>>b;
        v[m[a]][m[b]]++;
        point[m[a]]++;
        point[m[b]]--;
    }
    
    vector<int> cnt(v.size(),0);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(i==j) continue;
            if((v[i][j]==v[j][i]&&point[i]>point[j])||v[i][j]>v[j][i]) cnt[i]++;
        }
    }
    return *max_element(cnt.begin(),cnt.end());
}