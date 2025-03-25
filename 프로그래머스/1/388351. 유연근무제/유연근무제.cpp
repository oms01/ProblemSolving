#include <bits/stdc++.h>

using namespace std;

int conv(int n){
    int h = n/100;
    int m = n%100;
    return h*60 + m;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int ans = 0;
    
    int n = schedules.size();
    
    for(auto& x: schedules){
        x = conv(x) + 10;
    }
    
    for(int i=0;i<n;i++){
        bool flag = 1;
        for(int j=0;j<timelogs[i].size();j++){
            if((j+startday-1)%7>=5) continue;
            if(conv(timelogs[i][j]) > schedules[i]){
                flag = 0;
            }
        }
        cout<<'\n';
        ans += flag;
        
    }
    
    
    return ans;
}