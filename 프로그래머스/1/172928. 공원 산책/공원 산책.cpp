#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int vis[51][51];
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    map<char,pair<int,int>> m;
    m['N']={-1,0}; m['S']={1,0}; m['W']={0,-1}; m['E']={0,1}; 
    
    pair<int,int> pos = {0,0};
    for(int i=0;i<park.size();i++) for(int j=0;j<park[i].size();j++){
        if(park[i][j]=='S') pos = {i,j};
    }
    
    for(int i=0;i<routes.size();i++){
        char dir = routes[i][0];
        int dist = routes[i][2]-'0';
        
        bool chk = 1;
        for(int j=1;j<=dist;j++){
            int nx = pos.X + (m[dir].X*j);
            int ny = pos.Y + (m[dir].Y*j);
            if(nx<0||nx>=park.size()||ny<0||ny>=park[0].size()||park[nx][ny]=='X'){
                chk=0;
                break;
            }
        }
        
        if(!chk) continue;
        pos.X += (m[dir].X*dist);
        pos.Y += (m[dir].Y*dist);
    }
    
    answer.push_back(pos.X);
    answer.push_back(pos.Y);
    return answer;
}