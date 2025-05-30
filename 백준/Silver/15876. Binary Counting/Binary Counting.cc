#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

string conv(int n){
    string ret = "";
    if(n==0) return "0";
    while(n){
        ret+= "01"[n%2];
        n/=2;
    }
    reverse(all(ret));
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    int cnt = 0;
    while(v.size()<1000){
        for(auto x: conv(cnt)){
            v.push_back(x-'0');
        }
        cnt++;
    }

    int n,k; cin>>n>>k;
    cnt = 0;
    for(int i=k-1;cnt<5;i+=n){
        cout<<v[i]<<' ';
        cnt++;
    }

}