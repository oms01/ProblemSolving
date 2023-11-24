#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solution(vector<int> queue1, vector<int> queue2) {
    int ans = 0;
    vector<int> q = queue1;
    for(int i=0;i<queue2.size();i++) q.push_back(queue2[i]);
    ll sum = accumulate(q.begin(),q.end(),0LL)/2;
    ll cur = accumulate(queue1.begin(),queue1.end(),0LL);
    
    int st = 0;
    int en = queue1.size()-1;
    
    while(st<q.size() && en<q.size()){
        if(cur==sum) return ans;
        
        if(cur<sum && en<q.size()-1){
            cur+=q[++en];
        }
        else{
            cur-=q[st++];
        }
        ans++;
    }
    return -1;
}