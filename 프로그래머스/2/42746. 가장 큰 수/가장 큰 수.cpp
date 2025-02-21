#include <bits/stdc++.h>
using namespace std;


string solution(vector<int> numbers) {
    vector<string> v;
    bool flag = 0;
    for(auto n: numbers){
        v.push_back(to_string(n));
        if(n!=0) flag = 1;
    }
    if(!flag){
        return "0";
    }
    sort(v.begin(),v.end(),[&](string a, string b){
        return a+b > b+a;
    });
    
    string answer = "";
    for(auto x: v){
        answer+=x;
    }
    return answer;
}