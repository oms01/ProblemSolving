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
vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state(n+1, 1);
    for(int i=2;i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i){
            state[j] = 0;
        }
    }
    for(int i=2;i<=n;i++){
        if(state[i]) primes.push_back(i);
    }
    return primes;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v = sieve(8'000'001);
    int n; cin>>n;
    cout<<v[n-1]<<'\n';
}
