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


pii sum(pii a, pii b){
    int x = a.X*b.Y+b.X*a.Y;
    int y = a.Y*b.Y;
    return {x/__gcd(x,y),y/__gcd(x,y)};
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pii> v(n);
    rep(i,0,n){
        int x; cin>>x;
        v[i] = {1,x};
    }

    int cnt = 0;
    rep(brute,0,1<<n){
        pii s = {0,1};
        rep(i,0,n){
            if(brute&(1<<i)){
                s = sum(s,v[i]);
            }
        }
        if(s.Y*99 <= 100*s.X && 100*s.X <= s.Y*101){
            cnt++;
        }

    }
    cout<<cnt<<'\n';
}