#include <bits/stdc++.h>
using namespace std;

int arr[100'001];
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for(int i=0;i<section.size();i++){
        arr[section[i]] = 1;
    }
    for(int i=1;i<=n;i++){
        // cout<<i<<' ';
        if(arr[i]){
            answer++;
            i+=m-1;
        }
    }
    
    return answer;
    
}