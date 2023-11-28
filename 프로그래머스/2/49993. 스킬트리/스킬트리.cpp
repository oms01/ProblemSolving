#include <bits/stdc++.h>
using namespace std;
int alp[26];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int tmp = 1;
    for(auto x: skill) alp[x-'A']+=tmp++;
    
    for(auto cur : skill_trees){
        int idx = 1;
        bool flag = 1;
        for(int i=0;i<cur.size();i++){
            if(alp[cur[i]-'A'] > idx){
                flag = 0;
                break;
            }
            if(alp[cur[i]-'A']==idx) idx++;
        }
        answer+=flag;
    }
    return answer;
}