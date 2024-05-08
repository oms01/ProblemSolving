#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s!="1"){
        int cnt = 0;
        for(int i=0;i<s.length();i++) cnt+=(s[i]=='1');
        answer[1] += s.length()-cnt;
        answer[0]++;
        string tmp = "";
        while(cnt){
            tmp+=(cnt%2 ? '1':'0');
            cnt/=2;
        }
        reverse(tmp.begin(),tmp.end());
        s = tmp;
        // cout<<s<<'\n';
    }
    return answer;
}