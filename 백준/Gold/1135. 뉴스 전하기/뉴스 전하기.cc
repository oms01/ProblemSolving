#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

vector<int> adj[51];
int ans;
int func(int idx){ //idx의 총 통화 시간
    if(adj[idx].empty()) return 0;

    vector<int> tmp;
    for(int x: adj[idx]){
        tmp.push_back(func(x));
    }
    sort(all(tmp),greater<>());

    int ret = 0;
    rep(i,0,tmp.size()){
        ret = max(ret, tmp[i]+i+1);
    }
    return ret;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n){
        int x; cin>>x;
        if(x==-1) continue;
        adj[x].push_back(i);
    }
    cout<<func(0)<<'\n';

}