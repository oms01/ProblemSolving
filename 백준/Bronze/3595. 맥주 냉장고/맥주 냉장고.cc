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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    
    vector<ti3> v;
    
    REP(i,1,n) REP(j,1,i){
        if(i*j>n) break;
        REP(k,1,j){
            if(i*j*k>n) break;
            if(i*j*k==n){
                v.push_back({i,j,k});
            }
        }
    }

    auto [a,b,c] = v[0];
    cout<<a<<' '<<b<<' '<<c<<'\n';
}
