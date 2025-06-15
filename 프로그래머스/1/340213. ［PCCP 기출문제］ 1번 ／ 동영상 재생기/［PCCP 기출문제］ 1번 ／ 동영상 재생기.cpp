#include <bits/stdc++.h>
using namespace std;
int conv(string s){
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    return h*60+m;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int len = conv(video_len);
    int cur = conv(pos);
    int st = conv(op_start);
    int en = conv(op_end);
    
    if(st<=cur && cur<=en){
        cur = en;
    }
    for(auto com : commands){
        
        if(com=="next"){
            cur += 10;
            if(len-cur<10) cur = len;
        }
        else{
            cur -=10;
            if(cur<10) cur = 0;
        }
        
        if(st<=cur && cur<=en){
            cur = en;
        }
        
    }
    
    string h = to_string(cur/60);
    if(cur/60<10) h = "0" + h;
    string m = to_string(cur%60);
    if(cur%60<10) m = "0" + m;
    
    return h+":"+m;
}