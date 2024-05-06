#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    for(int i=0;i<len;i++){
        int cur = name[i]-'A';
        answer += min(26-cur, cur);
    }
    int cnt = len-1;
    for(int i=0;i<len;i++){
        int idx = i+1;
        while(name[idx]=='A'&& idx<len) idx++;
        
        cnt = min(cnt, i + len - idx + min(i, len-idx));
        
    }
    return answer+cnt;
}