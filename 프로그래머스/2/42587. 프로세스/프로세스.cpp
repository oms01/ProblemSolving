#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    for(auto x: priorities) pq.push(x);
    
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++) q.push({priorities[i],i});
        
    int cnt = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.first==pq.top()){
            if(cur.second == location){
                return cnt;
            }
            pq.pop();
            cnt++;
        }
        else{
            q.push(cur);
        }
    }
}