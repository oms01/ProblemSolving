#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int len=0;
    for(int i=0;i<arr.size();i++){
        len = max(len,(int)arr[i].size());
    }
    len = max(len,(int)arr.size());
    
    for(int i=0;i<arr.size();i++){
        while(arr[i].size()<len) arr[i].push_back(0);
    }
    vector<int> tmp(len,0);
    while(arr.size()<len) arr.push_back(tmp);
    return arr;
}