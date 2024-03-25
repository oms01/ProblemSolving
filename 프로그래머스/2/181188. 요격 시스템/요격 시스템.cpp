#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(int i=0;i<targets.size();i++){
        v.push_back({targets[i][0],i+1e9}); //시작점
        v.push_back({targets[i][1],i}); //끝점
    }
    sort(v.begin(),v.end());
    
    set<int> clear; //완료한거
    set<int> state; //현재 들고있는거
    for(int i=0;i<v.size();i++){
        int pos = v[i].X;
        int idx = v[i].Y;
        if(clear.find(idx)!=clear.end()){ //이미 처리한 미사일
            continue;
        }
        if(idx >= 1e9){ //시작점
            state.insert(idx-1e9);
        }
        else{ //끝점
            for(auto iter=state.begin();iter!=state.end();iter++){
                clear.insert(*iter);
            }
            state.clear();
            answer++;
        }
        
    }
    
    return answer;
}