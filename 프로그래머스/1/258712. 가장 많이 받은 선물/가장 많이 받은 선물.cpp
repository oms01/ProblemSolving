#include <bits/stdc++.h>
using namespace std;

pair<string,string> split(string str){
    int idx = 0;
    while(str[idx]!=' ') idx++;
    return {str.substr(0,idx), str.substr(idx+1,str.length())};
}
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string,int> m;
    vector<vector<int>> v(friends.size(),vector<int>(friends.size()));
    for(int i=0;i<friends.size();i++){
        m[friends[i]] = m.size();
    }
    map<int,int> point;
    for(int i=0;i<gifts.size();i++){
        pair<string, string> cur = split(gifts[i]);
        v[m[cur.first]][m[cur.second]]++;
        point[m[cur.first]]++;
        point[m[cur.second]]--;
    }
    
    map<int,int> cnt;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            int a = v[i][j];
            int b = v[j][i];
            if(a==b){
                //선물지수 비교
                if(point[i] > point[j]) cnt[i]++;
                else if(point[i] < point[j]) cnt[j]++;
            }
            else if(a>b) cnt[i]++;
            else if(a<b) cnt[j]++;
        }
    }
    
    for(auto i=cnt.begin();i!=cnt.end();i++){
        answer = max(answer,i->second);
    }
    
    return answer;
}