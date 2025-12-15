#include <bits/stdc++.h>
using namespace std;

int conv(string s){
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    return h*60+m;
}
string conv(int n){
    string ret = "";
    if(n/60 < 10) ret += "0";
    ret+=to_string(n/60);
    
    ret+=":";
    
    if(n%60 < 10) ret += "0";
    ret+=to_string(n%60);
    
    return ret;
}
string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> v;
    for(auto str: timetable){
        v.push_back(conv(str));
    }
    sort(v.begin(),v.end());
    
    int bus = 540;
    int idx = 0;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 0;
        while(cnt<m && idx<v.size() && v[idx] <= bus){
            cnt++;
            idx++;
        }
        
        if(i==n-1){
            if(cnt==m) ans = v[idx-1]-1;
            else ans = bus;
        }

        bus+=t;
        
    }
    
    return conv(ans);
}