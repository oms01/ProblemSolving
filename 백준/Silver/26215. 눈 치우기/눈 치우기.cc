#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int ans = 0;
    priority_queue<int> pq;
    rep(i,0,n){
        int val; cin>>val;
        pq.push(val);
    }
    while(pq.size()>1){
        int a = pq.top(); pq.pop(); 
        int b = pq.top(); pq.pop();
        ans += min(a,b);
        pq.push(abs(a-b));
    }
    if(!pq.empty()) ans+=pq.top();

    cout<<(ans>1440 ? -1 : ans);

}