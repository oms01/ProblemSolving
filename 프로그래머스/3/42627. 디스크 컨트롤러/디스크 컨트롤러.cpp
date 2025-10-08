#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> ti3;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(),jobs.end());
    
    priority_queue<ti3, vector<ti3>, greater<>> pq; //작업 소요시간, 작업 요청시간, 작업번호
    int cur = 0;
    int sum = 0;
    int i = 0;
    while(i<jobs.size() || !pq.empty()){
        while(i<jobs.size() && jobs[i][0] <= cur){
            pq.push({jobs[i][1], jobs[i][0], i++});
        }
        
        if(pq.empty()){
            cur = jobs[i][0];
        }
        else{
            auto [a,b,c] = pq.top(); pq.pop();
            cur += a;
            sum += cur-b;
        }
    }
    
    
    return sum/jobs.size();
}