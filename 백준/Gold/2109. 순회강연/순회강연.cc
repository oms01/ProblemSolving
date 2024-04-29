#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    priority_queue<int,vector<int>> pq[10001];
    rep(i,0,n){
        int a,b; cin>>a>>b;
        pq[b].push(a);
    }
    int ans = 0;
    priority_queue<int,vector<int>> tmp;
    for(int day=10000;day>=1;day--){
        while(!pq[day].empty()){
            tmp.push(pq[day].top()); pq[day].pop();
        }
        if(tmp.empty()) continue;
        ans += tmp.top(); tmp.pop();
    }
    cout<<ans<<'\n';
}