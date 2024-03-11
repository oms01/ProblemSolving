#include <bits/stdc++.h>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<char> v = {'A','C','F','J','M','N','R','T'};
int solution(int n, vector<string> data) {
    int answer = 0;
    sort(v.begin(),v.end());
    do{
        map<char,int> m;
        for(int i=0;i<v.size();i++){
            m[v[i]] = i;
        }
        bool flag = 1;
        
        for(int i=0;i<n;i++){
            char a = data[i][0];
            char b = data[i][2];
            char op = data[i][3];
            int val = data[i][4]-'0';
            int diff = abs(m[b]-m[a])-1;
            if(op=='='){
                if(val!=diff) flag = 0;
            }
            else if(op=='<'){
                if(val<=diff) flag = 0;
            }
            else if(op=='>'){
                if(val>=diff) flag = 0;
            }
            if(!flag) break;
        }
        if(flag) answer++;
        
        
    }while(next_permutation(v.begin(),v.end()));
    
    return answer;
}