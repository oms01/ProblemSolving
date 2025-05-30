#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int cur,p; 
map<int,int> ma;
int f(int n){
    string s = to_string(n);
    int ret = 0;
    for(auto x: s){
        int tmp = 1;
        rep(i,0,p) tmp*=x-'0';
        ret += tmp;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>cur>>p;
    ma[cur] = 1;
    while(1){
        int nxt = f(cur);
        if(ma[nxt]){
            return !(cout<<ma[nxt]-1<<'\n');
        }
        ma[nxt] = ma[cur]+1;
        cur = nxt;
    }
}