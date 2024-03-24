#include <bits/stdc++.h>
using namespace std;



int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int time = 0;
    int curhp = health;
    for(int i=0;i<attacks.size();i++){
        int curT = attacks[i][0];
        curhp += (curT-time-1)*bandage[1];
        curhp += (curT-time-1)/bandage[0] * bandage[2];
        
        curhp = min(curhp, health);
        
        curhp -= attacks[i][1];
        time = curT;
        if(curhp<=0) return -1;
    }
    
    return curhp;
}