#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

vector<int> adj[101];
int func(int x, pii erase){
    vector<bool> vis(101,0);
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    int cnt = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(cur==erase.X && nxt==erase.Y) continue;
            if(cur==erase.Y && nxt==erase.X) continue;
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
            cnt++;
        }
    }
    return cnt;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 2e9;
    
    for(int i=0;i<wires.size();i++){
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0;i<wires.size();i++){
        pii erase = {wires[i][0], wires[i][1]};
        vector<int> tmp;
        for(int i=0;i<n;i++){
            tmp.push_back(func(i+1,erase));
        }
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        if(tmp.size()==1){
            return 0;
        }
        answer = min(answer, abs(tmp[0]-tmp[1]));
    }
    return answer;
}