#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b;
    char c;
    cin>>a>>c>>b;
    if(c=='*'){
        cout<<1;
        for(int i=a.size()+b.size()-2;i;i--) cout<<0;
    }
    else{
        for(int i=max(a.size(),b.size());i;i--){
            cout<<(i==a.size())+(i==b.size());
        }
    }

}
