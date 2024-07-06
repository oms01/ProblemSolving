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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    cout<<n*(n-1)/2<<'\n';
    rep(i,0,n) cout<<(1<<i)<<' ';
    cout<<'\n';

    cout<<n-1<<'\n';
    rep(i,0,n) cout<<i+1<<' ';
    cout<<'\n';
}