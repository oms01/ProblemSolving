#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
set<int> sieve(int n){
    set<int> ret;
    vector<bool> state(n+1,1);
    state[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i) state[j] = 0;
    }
    for(int i=2;i<=n;i++){
        if(state[i]) ret.insert(i);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    set<int> prime = sieve(100'000);

    string str;
    while(cin>>str){
        if(str=="0") break;
        int ans = -1;
        rep(i,0,str.length()) rep(j,1,7){
            int n = stoi(str.substr(i,j));
            if(prime.find(n)==prime.end()) continue;
            ans = max(ans,n);
        }
        cout<<ans<<'\n';

    }

}