#include <bits/stdc++.h>
using namespace std;


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 2e9;
    
    //sort(dist.begin(),dist.end(),greater<>());
    
    do{
    //시계방향으로만 돌거임
    for(int i=0;i<weak.size();i++){ //시작점 weak[i]

        vector<int> order; //방문 순서 저장
        for(int j=0;j<weak.size();j++){
            order.push_back(weak[(i+j)%weak.size()]);
        }
        
        bool vis[300];
        fill(vis,vis+300,0);
        
        // cout<<weak[i]<<" : ";
        // for(int j=0;j<order.size();j++){
        //     cout<<order[j]<<' ';
        // }
        // cout<<'\n';
        
        for(int j=0;j<dist.size();j++){
            int cnt = 0;
            int st = 0;
            for(int k=0;k<order.size();k++){
                if(vis[order[k]]==0){
                    st = order[k];
                    break;
                }
            }
            int en = st + dist[j];
            //cout<<st<<','<<en<<":";
            //st~en까지 방문 가능
            for(int k=st;k<=en;k++) vis[k%n] = 1;
            
            
            for(int j=0;j<weak.size();j++){ //방문한 지점 수 count
                if(vis[weak[j]]==1){
                    cnt++;
                }
            }
            //cout<<cnt<<'\n';
            
            if(cnt>=weak.size()){
                answer = min(answer,j+1);
            }
        }
        
        
    }
    }while(next_permutation(dist.begin(),dist.end()));
    
    
    return answer==2e9 ? -1 : answer;
}