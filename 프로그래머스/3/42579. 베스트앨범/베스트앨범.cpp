#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,vector<pair<int,int>>> m;
    map<string,int> cnt;
    for(int i=0;i<genres.size();i++){
        m[genres[i]].push_back({-plays[i],i});
        cnt[genres[i]]+=plays[i];
    }
    vector<pair<string,int>> tmp;
    for(auto x: cnt) tmp.push_back(x);
    sort(tmp.begin(),tmp.end(),[&](pair<string,int> a, pair<string,int> b){
         return a.second > b.second;
    });
    
    for(auto& [a,b]: m){
        sort(b.begin(),b.end());
    }
    for(auto x: tmp){
        for(int i=0;i<min((int)m[x.first].size(),2);i++){
            answer.push_back(m[x.first][i].second);
        }
    }

    return answer;
}