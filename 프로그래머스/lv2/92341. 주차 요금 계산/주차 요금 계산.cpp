#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int,pair<int,bool>>> data; // carNum, minute, state
    for(int i=0;i<records.size();i++){
        string str = records[i];
        string arr[3];
        
        int idx=0;
        string tmp = "";
        for(int j=0;j<str.size();j++){
            if(str[j]==' '){
                arr[idx++] = tmp;
                tmp = "";
            }
            else tmp+=str[j];
        }
        arr[2] = tmp;
        
        int carNum = stoi(arr[1]);
    
        int h = (arr[0][0]-'0')*10 + (arr[0][1]-'0');
        int m = (arr[0][3]-'0')*10 + (arr[0][4]-'0');
        int minute = h*60 + m;
        
        bool state = (arr[2]=="IN") ? 1 : 0;
        
        data.push_back({carNum,{minute, state}});
    }
    
    
    sort(data.begin(),data.end());
    vector<pair<int,bool>> arr[11111];
    set<int> carnums;
    for(int i=0;i<data.size();i++){
        arr[data[i].X].push_back({data[i].Y.X, data[i].Y.Y});
        carnums.insert(data[i].X);
    }
    
    for(int idx:carnums){
        if(arr[idx].size()%2==1){
            arr[idx].push_back({24*60-1,0});
        }
        int time = 0;
        for(int i=0;i<arr[idx].size();i+=2){
            time += (arr[idx][i+1].X - arr[idx][i].X);
        }
        // 180, 5000, 10, 600
        //fees : {기본 시간(분), 기본 요금, 단위 시간(분), 단위 요금}
        if(time > fees[0]){
            int a = fees[1] + ceil((time-fees[0])/(double)fees[2]) * fees[3];  
            answer.push_back(a);
        }
        else{
            answer.push_back(fees[1]);
        }
    }
    
    

    return answer;
}