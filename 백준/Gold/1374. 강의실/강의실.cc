#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pii> v;
    rep(i,0,n){
        int s,e,x;
        cin>>x>>s>>e;
        v.push_back({s,e});
    }
    sort(v.begin(),v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    rep(i,0,n){
        while(!pq.empty() && pq.top() <= v[i].X) pq.pop();
        pq.push(v[i].Y);
        ans = max(ans,(int)pq.size());
    }
    cout<<ans<<'\n';

}

