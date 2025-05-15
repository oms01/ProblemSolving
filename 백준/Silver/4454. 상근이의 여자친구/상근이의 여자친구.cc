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
ld a,b,c,d,m,t;
ld f(ld v){
    return (a*v*v*v*v + b*v*v*v + c*v*v + d*v)*m/v;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout<<fixed;
    cout.precision(2);
    while(cin>>a>>b>>c>>d>>m>>t){

        ld mx = -2e9;
        ld st = 0, en = 1000;
        while(en-st>=0.00001){
            ld v = (st+en)/2;
            
            ld gas = f(v);
            if(gas<=t){
                st = v;
            }
            else{
                en = v;
            }
        }
        cout<<(st-0.005)<<'\n';
    }
}