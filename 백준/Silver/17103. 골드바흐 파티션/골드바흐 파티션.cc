#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
set<int> sieve(int n){
    set<int> primes;
    vector<bool> state(n+1,1);
    state[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i) state[j] = 0;
    }
    for(int i=2;i<=n;i++){
        if(state[i]) primes.insert(i);
    }
    return primes;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    set<int> s = sieve(1'000'000);
    while(t--){
        int n; cin>>n;
        int cnt = 0;
        for(auto i=s.begin();i!=s.end();i++){
            if(*i*2>n) break;
            if(s.find(n-*i)!=s.end()){
                // cout<<*i<<'+'<<n-*i<<'\n';
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}

