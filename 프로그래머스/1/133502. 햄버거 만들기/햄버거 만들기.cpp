#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> v) {
    int answer = 0;
    stack<int> s;
    for(int i=0;i<v.size();i++){
        if(s.empty()) s.push(v[i]==1);
        else if(!s.empty()){
            if((s.top()==1 && v[i]==2)||(s.top()==2 && v[i]==3)) s.push(v[i]);
            else if(s.top()==3 && v[i]==1){
                answer++;
                s.pop(); s.pop(); s.pop();
            }
            else s.push(v[i]==1);
        }
    }

    return answer;
}