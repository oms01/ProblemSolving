#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> v(n+1,1);
    for(int i=0;i<reserve.size();i++) v[reserve[i]]++;
    for(int i=0;i<lost.size();i++) v[lost[i]]--;
    sort(reserve.begin(),reserve.end());
    for(int i=0;i<reserve.size();i++){
        if(v[reserve[i]]!=2) continue;
        if(reserve[i]-1>0 && v[reserve[i]-1]==0){
            v[reserve[i]-1]++;
            v[reserve[i]]--;
        }
        else if(reserve[i]+1<=n && v[reserve[i]+1]==0){
            v[reserve[i]+1]++;
            v[reserve[i]]--;
        }
    }
    for(int i=1;i<=n;i++){
        answer -= !v[i];
    }

    
    return answer;
}