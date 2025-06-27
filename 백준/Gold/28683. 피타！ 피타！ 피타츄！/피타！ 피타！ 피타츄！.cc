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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const ll MX = 1e12;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    if(sqrt(n)==(ll)sqrt(n)) return !(cout<<-1<<'\n');
    
    set<pll> s;
    for(ll i=1;i*i<=n;i++){
        ll rt = sqrt(n-i*i);
        if(rt*rt==n-i*i){
            s.insert({min(i,rt),max(i,rt)});
        }
    }

    for(ll i=1;i*i<=n;i++){
        if(n%i!=0) continue;
        ll a = i;
        ll b = n/i;
        if(a%2==b%2){
            s.insert({min(a,b),max(a,b)});
        }
    }
    cout<<s.size()<<'\n';
}