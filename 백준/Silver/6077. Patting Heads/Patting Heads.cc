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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
vector<int> f(int n){
    vector<int> ret;
    for(int i=1;i*i<=n;i++){
        if(n%i==0) ret.push_back(i);
    }
    for(int i=ret.size()-1;i>=0;i--){
        if(ret[i]*ret[i]!=n) ret.push_back(n/ret[i]);
    }
    return ret;
}
int cnt[1'000'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n);
    map<int,int> m;
    rep(i,0,n){ cin>>v[i]; m[v[i]]++;}

    for(auto cur : m){
        for(int x:f(cur.X)){
            if(m.find(x)==m.end()) continue;
            cnt[cur.X]+=m[x];
        }
    }
    rep(i,0,n){
        cout<<cnt[v[i]]-1<<'\n';
    }

}