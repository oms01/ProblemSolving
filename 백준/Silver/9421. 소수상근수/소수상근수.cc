#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 1'000'000;
int cal(int n){
    string s = to_string(n);
    int ret = 0;
    for(auto x: s){
        int a = x-'0';
        ret += a*a;
    }
    return ret;
}
vector<int> sieve(){
    vector<bool> state(MX+1,1);
    vector<int> ret;
    for(int i=2;i*i<=MX;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=MX;j+=i){
            state[j] = 0;
        }
    }
    for(int i=2;i<=MX;i++){
        if(state[i]) ret.push_back(i);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> state(MX+1,1);
    state[1] = 0;
    vector<int> prime = sieve();
    vector<int> ans(MX+1,0);
    for(auto x: prime){
        if(!state[x]) continue;
        int cur = x;
        vector<int> v;
        while(state[cur]){
            v.push_back(cur);
            state[cur] = 0;
            cur = cal(cur);
        }
        if(cur==1){
            ans[x] = 1;
            for(auto x: v){
                state[x] = 1;
            }
        }
    }
    
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        if(ans[i]) cout<<i<<'\n';
    }

}