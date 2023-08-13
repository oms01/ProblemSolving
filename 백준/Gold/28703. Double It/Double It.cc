#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    priority_queue<int, vector<int> ,greater<int>> pq;
    int mx = 0;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        mx = max(mx,v);
        pq.push(v);
    }

    int curmx = mx, ans = curmx-pq.top();
    while(pq.top()<mx){
        int v = pq.top(); pq.pop(); //pq의 제일 작은 값
        ans = min(ans,curmx-v);
        curmx = max(curmx,2*v); //배열의 가장 큰 값
        pq.push(2*v);
    }
    cout<<min(curmx-pq.top(),ans);
}
