#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    int cnt = 0;
    vector<int> lmn(n,2e9), rmn(n,2e9);
    lmn[0] = a[0];
    for(int i=1;i<n;i++){
        lmn[i] = min(lmn[i-1], a[i]);
    }
    rmn[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        rmn[i] = min(rmn[i+1], a[i]);
    }

    for(int i=0;i<n;i++){
        if((rmn[i] < a[i] && lmn[i] < a[i])){
            cnt++;
        }
    }
    return n-cnt;
}