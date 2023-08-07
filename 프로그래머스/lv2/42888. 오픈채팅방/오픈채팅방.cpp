#include<bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> data;
    for(int i=0;i<record.size();i++){
        vector<string> tmp;
        stringstream ss(record[i]);
        string str;
        while(getline(ss,str,' ')){
            tmp.push_back(str);
        }
        data.push_back(tmp);
    }
    /*
    data.size = record.size
    data[i][0] = order {Enter, Leave, Change}
    data[i][1] = uid {string}
    data[i][2] = name {string}
    */
    
    map<string,string> m; // {uid, name}
    for(int i=0;i<data.size();i++){
        if(data[i][0]=="Leave") continue;
        m[data[i][1]] = data[i][2];
    }
    
    for(int i=0;i<data.size();i++){
        if(data[i][0]=="Enter"){
            string str = m[data[i][1]]+"님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if(data[i][0]=="Leave"){
            string str = m[data[i][1]]+"님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    
    
     return answer;
}