#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<ll,ll> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<int> v[200'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        v[a].push_back(b); //데드라인, 보상
    }

    int ans = 0;
    priority_queue<int,vector<int>> tmp;
    int cur = 2e9;
    for(int i=n;i>=1;i--){
        for(auto x: v[i]) tmp.push(x);
        if(tmp.empty()) continue;
        ans+=tmp.top(); tmp.pop();
    }
    cout<<ans<<'\n';
}