#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    for(int i=0;i<pow(2,n);i++){
        int cur = i;
        int res = 0;
        for(int j=0;j<n;j++){
            if(cur%2) res += numbers[j];
            else res -= numbers[j];
            cur/=2;
        }
        if(res==target) answer++;
    }
    return answer;
}