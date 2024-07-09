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
const ll MX = 10'000'000;
bool state[MX+1];
vector<ll> sieve(){
    vector<ll> prime;
    memset(state,1,sizeof(state));
    state[1] = 0;
    for(int i=2;i*i<=MX;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=MX;j+=i) state[j] = 0;
    }
    for(int i=2;i<=MX;i++){
        if(state[i]) prime.push_back(i);
    }

    return prime;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ll> prime = sieve(); // 10^7 이하 소수
    ll s,e; cin>>s>>e;
    ll cnt = 0;
    rep(i,0,prime.size()){
        ll cur = prime[i];
        for(ll j = cur*cur; j<=MX*MX;j*=cur){
            if(s<=j && j<=e) cnt++;
            
            if(j >= MX*MX/cur) break;
        }
    }

    cout<<cnt<<'\n';

}