#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> info;
int mx;
vector<int> answer;
set<vector<int>> s;

int cmp(vector<int> v){
    int a=0, b=0; //어피치 , 라이언 점수
    for(int i=0;i<=10;i++){
        if(v[i]==0 && info[i]==0) continue;
        if(v[i] > info[i]) b+=(10-i);
        else a+=(10-i);
    }
    return b-a;
}

void func(int cnt, vector<int> v){
    if(s.find(v)!=s.end()) return;
    s.insert(v);
    if(cnt==n){
        int diff = cmp(v);
        if(mx < diff){
            mx = diff;
            answer = v;
        }
        return;
    }
    for(int i=10;i>=0;i--){
        v[i]++;
        func(cnt+1, v);
        v[i]--;
    }
}

vector<int> solution(int a, vector<int> infomation) {
    info = infomation; n = a;
    
    vector<int> tmp(11,0);
    
    func(0,tmp);
    if(answer.empty()){
        vector<int> fail(1,-1);
        return fail;
    }
    return answer;
}