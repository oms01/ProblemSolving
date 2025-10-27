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
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    ll mx = 1e18;
    ll mn = -1e18;
    int idx = -1;
    REP(i,1,t){
        ll x; char c;
        cin>>x>>c;
        
        if(c=='^'){
            mn = max(mn,x+1);
        }
        else{
            mx = min(mx,x-1);
        }
        if(mx<mn) return !(cout<<"Paradox!\n"<<i<<'\n');
        if(mn==mx && idx == -1){
            idx = i;
        }
    }
    if(idx!=-1){
        return !(cout<<"I got it!\n"<<idx<<'\n');
    }
    cout<<"Hmm...\n";
}