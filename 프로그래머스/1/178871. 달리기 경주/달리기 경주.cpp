#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    list<string> li;
    map<string,list<string>::iterator> ptr;
    for(int i=0;i<players.size();i++){
        li.push_back(players[i]);
        ptr[players[i]] = prev(li.end());
    }
    
    for(int i=0;i<callings.size();i++){
        string front = *prev(ptr[callings[i]]);
        
        li.erase(ptr[front]);
        li.insert(next(ptr[callings[i]]), front);
        ptr[front] = next(ptr[callings[i]]);
    }
    for(auto iter = li.begin();iter!=li.end();iter++){
        answer.push_back(*iter);
    }
    return answer;
}