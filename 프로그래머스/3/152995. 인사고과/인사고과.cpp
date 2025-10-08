#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) {
    int ans = 1;
    int a = scores[0][0];
    int b = scores[0][1];
    
    sort(scores.begin(),scores.end(),[](vector<int> a, vector<int> b){
        if(a[0]==b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    
    int mxb = -2e9;
    for(int i=0;i<scores.size();i++){
        int x = scores[i][0];
        int y = scores[i][1];
        mxb = max(mxb,y);
        if(a<x && b<y) return -1;
        if(mxb == y){
            if(a+b < x+y) ans++;
        }
    }
    
    return ans;
}