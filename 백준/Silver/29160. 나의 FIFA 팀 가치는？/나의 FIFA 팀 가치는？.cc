#include <bits/stdc++.h>
using namespace std;
priority_queue<int> team[12];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        team[a].push(b);
    }
    while(k--){
        for(int i=1;i<=11;i++){
            if(team[i].empty()) continue;
            int cur = team[i].top()-1; team[i].pop();
            if(cur>0) team[i].push(cur);
        }
    }
    int ans = 0;
    for(int i=1;i<=11;i++){
        if(team[i].empty()) continue;
        ans+=team[i].top();
    }
    cout<<ans<<'\n';
}