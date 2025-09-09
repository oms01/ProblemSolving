#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;
int p[MX+1];
int Find(int a){
    if(a==p[a]) return a;
    return p[a] = Find(p[a]);
}
void Union(int a,int b){
    a = Find(a); b = Find(b);
    if(a!=b) p[a] = b;
}

vector<int> adj[MX+1];
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    
    for(int i=0;i<=MX;i++) p[i] = i;
    
    for(auto e: edges){
        Union(e[0],e[1]);
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    map<int,vector<int>> trees;
    for(auto n: nodes) trees[Find(n)].push_back(n);
    
    vector<int> ans(2,0);
    for(auto [num,x]: trees){
        int Acnt = 0, Bcnt = 0;
        for(auto node : x){
            if((node%2)^(adj[node].size()%2)){
                Acnt++;
            }
            else{
                Bcnt++;
            }
        }
        if(Acnt==1) ans[1]++;
        if(Bcnt==1) ans[0]++;
    }
    
    return ans;
}