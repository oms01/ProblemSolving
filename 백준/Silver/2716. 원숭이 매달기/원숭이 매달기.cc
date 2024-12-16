#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

void solve(){
    string s;
    getline(cin,s);

    int dep = 0, mx = 0;
    for(auto c: s){
        dep += (c=='[' ? 1 : -1);
        mx = max(mx, dep);
    }
    cout<<(1<<mx)<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin>>t;
    cin.ignore();
    while(t--){
        solve();
    }
}