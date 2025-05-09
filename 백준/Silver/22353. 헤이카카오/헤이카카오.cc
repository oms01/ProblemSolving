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

int a,d,k;
ld f(ld p){
    if(p>1) return 1;
    return 1 + (1-p)*f(p*(1+k*0.01));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>d>>k;
    cout<<fixed;
    cout.precision(10);
    cout<<a*f(d*0.01)<<'\n';
}