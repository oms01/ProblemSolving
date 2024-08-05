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
    set<int> prime;
    vector<int> state(n+1,true);
    state[1] = false;
    for(int i=2;i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i){
            state[j] = false;
        }
    }
    for(int i=2;i<=n;i++){
        if(state[i]) prime.insert(i);
    }
    return prime;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    set<int> s = sieve(n);
    
    if(n<8){
        cout<<-1<<'\n';
    }
    vector<int> v(4);
    if(n%2==0){
        n-=4;
        v[0] = 2; v[1] = 2;
    }
    else{
        n-=5;
        v[0] = 2; v[1] = 3;
    }
    for(auto x : s){
        if(s.find(n-x)!=s.end()){
            v[2] = x; v[3] = n-x;
            break;
        }
    }
    
    for(auto x : v){
        cout<<x<<' ';
    }
    cout<<'\n';

}
