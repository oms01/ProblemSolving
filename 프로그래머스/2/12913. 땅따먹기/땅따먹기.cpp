#include <bits/stdc++.h>
using namespace std;
int dp[100'001][10];
int solution(vector<vector<int> > land){
    for(int i=1;i<land.size();i++){
        for(int j=0;j<4;j++){
            
            int mx = -1;
            for(int k=0;k<4;k++){
                if(j==k) continue;
                mx = max(mx,land[i-1][k]);
            }
            
            land[i][j] += mx;
        }
    }
    
    int ans = -1;
    for(int i=0;i<4;i++){
        ans = max(ans,land[land.size()-1][i]);
    }
    return ans;
}